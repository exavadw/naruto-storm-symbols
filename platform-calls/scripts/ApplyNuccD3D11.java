// Annotate Direct3D 11 / DXGI COM calls and platform imports (nucc-d3d11 package) in the current program.
// Comments only, nothing is renamed: an end-of-line comment at each call site ("[d3d11] ID3D11DeviceContext::DrawIndexed")
// and a plate-comment line per function listing what it uses. Refuses to run unless the program's SHA-256 matches
// meta.json beside the CSVs.
// Headless: analyzeHeadless <proj> <name> -process <prog> -postScript ApplyNuccD3D11.java <dir with calls.csv>
//@category NUCC
import java.io.*;
import java.nio.file.*;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class ApplyNuccD3D11 extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File dir = args.length > 0 ? new File(args[0]) : askDirectory("nucc-d3d11 folder for this exe", "Apply");
        File meta = new File(dir, "meta.json");
        if (meta.exists()) {
            String m = new String(Files.readAllBytes(meta.toPath()));
            String want = m.replaceAll("(?s).*\"exe_sha256\"\\s*:\\s*\"([0-9a-fA-F]+)\".*", "$1");
            String have = currentProgram.getExecutableSHA256();
            if (have == null || !have.equalsIgnoreCase(want)) {
                printerr("SHA-256 mismatch: program " + have + " but data is for " + want + ". Not applying.");
                return;
            }
        }
        long base = currentProgram.getImageBase().getOffset();
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        Map<Address, TreeSet<String>> perFunc = new HashMap<>();
        int sites = 0;
        for (String[] spec : new String[][] {{"calls.csv", "d3d11"}, {"imports.csv", "import"}}) {
            File csv = new File(dir, spec[0]);
            if (!csv.exists()) continue;
            try (BufferedReader r = new BufferedReader(new FileReader(csv))) {
                String[] head = r.readLine().split(",");
                Map<String, Integer> col = new HashMap<>();
                for (int i = 0; i < head.length; i++) col.put(head[i], i);
                String line;
                while ((line = r.readLine()) != null && !monitor.isCancelled()) {
                    String[] f = line.split(",", -1);
                    Address fa = toAddr(base + Long.decode(f[col.get("function_rva")]));
                    Address ca = toAddr(base + Long.decode(f[col.get("call_rva")]));
                    String what = spec[1].equals("d3d11") ? f[col.get("interface")] + "::" + f[col.get("method")] : f[col.get("import")];
                    String tag = "[" + spec[1] + "] " + what;
                    String old = listing.getComment(CodeUnit.EOL_COMMENT, ca);
                    if (old == null || !old.contains(tag)) {
                        listing.setComment(ca, CodeUnit.EOL_COMMENT, old == null ? tag : old + "; " + tag);
                        sites++;
                    }
                    perFunc.computeIfAbsent(fa, k -> new TreeSet<>()).add(spec[1].equals("d3d11") ? f[col.get("method")] : what);
                }
            }
        }
        for (Map.Entry<Address, TreeSet<String>> e : perFunc.entrySet()) {
            Function fn = fm.getFunctionAt(e.getKey());
            if (fn == null) continue;
            String tag = "[d3d11/platform] " + String.join(", ", e.getValue());
            String old = fn.getComment();
            if (old != null && old.contains("[d3d11/platform]")) continue;
            fn.setComment(old == null ? tag : old + "\n" + tag);
        }
        println(String.format("nucc-d3d11: %d call sites commented in %d functions", sites, perFunc.size()));
    }
}
