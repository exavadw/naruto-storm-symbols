// Apply NUCC function names (functions.csv) to the current program.
// Refuses to run unless the program's SHA-256 matches the CSV's build (meta.json beside it, or the first argument).
// high   -> function renamed (C++ namespaces/classes created from "A::B::name")
// medium -> renamed + plate comment "[nucc medium <methods>]"
// low    -> default name kept; plate comment "[nucc low] maybe <name> (<methods>)"
// Headless: analyzeHeadless <proj> <name> -process <prog> -postScript ApplyNuccNames.java <functions.csv> [min_confidence]
//@category NUCC
import java.io.*;
import java.nio.file.*;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.app.util.NamespaceUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class ApplyNuccNames extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File csv = args.length > 0 ? new File(args[0]) : askFile("NUCC functions.csv", "Apply");
        String minConf = args.length > 1 ? args[1] : "low";
        int min = rank(minConf);

        File meta = new File(csv.getParentFile(), "meta.json");
        boolean va = false;
        if (meta.exists()) {
            String m = new String(Files.readAllBytes(meta.toPath()));
            va = m.matches("(?s).*\"address_kind\"\\s*:\\s*\"VA.*");
            String want = m.replaceAll("(?s).*\"exe_sha256\"\\s*:\\s*\"([0-9a-fA-F]+)\".*", "$1").toLowerCase();
            String have = currentProgram.getExecutableSHA256();
            if (have == null || !have.equalsIgnoreCase(want)) {
                printerr("SHA-256 mismatch: program " + have + " but names are for " + want + ". Not applying.");
                return;
            }
        } else {
            println("warning: no meta.json beside the CSV; skipping the SHA-256 check");
        }

        long base = va ? 0 : currentProgram.getImageBase().getOffset();   // console builds list absolute VAs
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        int renamed = 0, commented = 0, created = 0, skipped = 0;
        try (BufferedReader r = new BufferedReader(new FileReader(csv))) {
            String[] head = splitCsv(r.readLine());
            Map<String, Integer> col = new HashMap<>();
            for (int i = 0; i < head.length; i++) col.put(head[i], i);
            String line;
            while ((line = r.readLine()) != null && !monitor.isCancelled()) {
                String[] f = splitCsv(line);
                String conf = f[col.get("confidence")];
                if (rank(conf) < min) { skipped++; continue; }
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace()
                    .getAddress(base + Long.decode(f[col.get("rva")]));
                String name = f[col.get("name")], methods = f[col.get("methods")];
                Function fn = fm.getFunctionAt(a);
                if (fn == null) {
                    disassemble(a);
                    fn = createFunction(a, null);
                    if (fn == null) { skipped++; continue; }
                    created++;
                }
                if (conf.equals("low")) {
                    appendPlate(fn, "[nucc low] maybe " + name + " (" + methods + ")");
                    commented++;
                    continue;
                }
                int sep = name.lastIndexOf("::");
                Namespace ns = currentProgram.getGlobalNamespace();
                String shortName = name;
                if (sep > 0) {
                    ns = NamespaceUtils.createNamespaceHierarchy(name.substring(0, sep), null, currentProgram, SourceType.IMPORTED);
                    shortName = name.substring(sep + 2);
                }
                try {
                    fn.setParentNamespace(ns);
                    fn.setName(shortName, SourceType.IMPORTED);
                    renamed++;
                } catch (Exception e) {
                    appendPlate(fn, "[nucc] " + name + " (rename failed: " + e.getMessage() + ")");
                    commented++;
                    continue;
                }
                if (conf.equals("medium")) appendPlate(fn, "[nucc medium " + methods + "]");
            }
        }
        println(String.format("NUCC names: %d renamed, %d comment-only, %d functions created, %d skipped (min confidence %s)",
            renamed, commented, created, skipped, minConf));
    }

    private void appendPlate(Function fn, String text) {
        String old = fn.getComment();
        if (old != null && old.contains(text)) return;
        fn.setComment(old == null ? text : old + "\n" + text);
    }

    private static int rank(String c) {
        return c.equals("high") ? 3 : c.equals("medium") ? 2 : 1;
    }

    private static String[] splitCsv(String line) {
        List<String> out = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        boolean q = false;
        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if (q) {
                if (c == '"' && i + 1 < line.length() && line.charAt(i + 1) == '"') { cur.append('"'); i++; }
                else if (c == '"') q = false;
                else cur.append(c);
            } else if (c == '"') q = true;
            else if (c == ',') { out.add(cur.toString()); cur.setLength(0); }
            else cur.append(c);
        }
        out.add(cur.toString());
        return out.toArray(new String[0]);
    }
}
