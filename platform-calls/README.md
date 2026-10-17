# NUCC platform-call annotations (Direct3D 11 / 9, DXGI, input, audio, Win32, Steam)

Companion to the function names in `../games/`, kept separate on purpose: these are *annotations*, not names. For each PC build of
CyberConnect2's NARUTO STORM series they mark where the game calls into the platform:

- `imports.csv` — every direct call to an imported DLL function (`dll!function`), per function and call site: D3D11 /
  D3D9 / D3DCompiler / DXGI / XInput / DirectInput / Steam / Win32 / sockets. Exact (read from the import table).
- `calls.csv` — Direct3D COM method calls (`ID3D11DeviceContext::DrawIndexed`, ...) at call sites where the object
  type is proven: traced from its creator (`D3D11CreateDevice`, `CreateDXGIFactory`, `ID3D11Device::Create*`,
  `D3DCompile`, ...) through fields of the creating class, locals and parameters. Precision first.
- `steam.csv` — Steamworks interface method calls (`ISteamMatchmaking::CreateLobby`, `ISteamUserStats::SetAchievement`,
  ...) on pointers returned by the Steam accessors (`SteamUser()`, ... or Connections' inlined
  `SteamInternal_ContextInit` accessors). Method order per interface version from the historical SDK headers (as kept by
  the Goldberg emulator project); `versions` names the interface version used. Versions: Storm 4 from its own
  `steam_api64.dll`, Connections from the version strings in its exe, 64-bit Storm 1–3 use Storm 4's SDK (its tables fit
  their calls' argument counts exactly), and the 32-bit 2014 builds (Full Burst, Revolution) name only the slots every
  plausible version agrees on.

**No game files are included** — addresses and API names only. Annotations apply only to the exact exe (SHA-256 in
`meta.json`).

| Build | SHA-256 | Import calls | in functions | COM calls (proven) | Steam calls | Top DLLs |
|---|---|---|---|---|---|---|
| Storm 1 PC (NSUNS1.exe) | `10231093af9c…` | 2,008 | 786 | 76 | 26 | kernel32.dll 1812, user32.dll 72, steam_api64.dll 43, ole32.dll 39 |
| Storm 1 PC debug build (NSUNS1(debug).exe) | `d209f8d0c035…` | 1,245 | 512 | 55 | 18 | kernel32.dll 1055, user32.dll 73, ole32.dll 38, steam_api64.dll 36 |
| Storm 2 PC (NSUNS2.exe) | `697488011750…` | 2,141 | 872 | 76 | 178 | kernel32.dll 1732, steam_api64.dll 254, user32.dll 72, ole32.dll 39 |
| Storm 3 HD PC (NSUNS3.exe) | `55b726e94dad…` | 2,174 | 890 | 76 | 178 | kernel32.dll 1758, steam_api64.dll 260, user32.dll 72, ole32.dll 39 |
| Storm 3 Full Burst PC 2014 (NS3FB.exe) | `5373bfd6308c…` | 1,591 | 530 | 0 | 90 | kernel32.dll 1246, steam_api.dll 258, user32.dll 34, ws2_32.dll 22 |
| Storm 4 PC debug 1.06 | `8324cc6d2e0f…` | 1,725 | 753 | 55 | 153 | kernel32.dll 1198, steam_api64.dll 194, ws2_32.dll 167, user32.dll 77 |
| Storm 4 PC release (NSUNS4.exe) | `147e52a3e0d7…` | 2,410 | 1,002 | 76 | 188 | kernel32.dll 1845, steam_api64.dll 264, ws2_32.dll 137, user32.dll 74 |
| Storm Revolution PC (NSUNSR.exe) | `a123d39ed684…` | 1,609 | 546 | 0 | 98 | kernel32.dll 1258, steam_api.dll 254, user32.dll 36, ws2_32.dll 27 |
| Storm Connections PC (NSUNSC.exe) | `cecf0405b5ac…` | 1,624 | 789 | 66 | 184 | kernel32.dll 838, steam_api64.dll 435, ws2_32.dll 163, user32.dll 115 |

## Applying (comments only, nothing is renamed)

- Ghidra: run `scripts/ApplyNuccD3D11.java`, pick `games/<game>/<sha256>/` (headless: `-postScript ApplyNuccD3D11.java <dir>`).
  End-of-line comments `[d3d11] ID3D11DeviceContext::DrawIndexed` / `[steam] ISteamMatchmaking::CreateLobby` /
  `[import] d3d11.dll!D3D11CreateDevice` at each call
  site, plus a `[d3d11/platform] ...` line in each function's plate comment.
- IDA 7.4+: File → Script file → `scripts/apply_nucc_d3d11_ida.py`, pick the build's `calls.csv`.

## Limits (honest)

- COM coverage is small on purpose. Most of the engine reaches D3D through its own wrapper objects; proving the type of
  those pointers without names or class layouts produced too many false positives (an audio function "calling"
  `IASetInputLayout`), so only calls whose object type is traced are listed. Expect tens of calls per build, mostly in
  device/swap-chain/shader setup; the per-frame draw code is reached through wrappers that aren't typed yet.
- The 2014 builds (Full Burst, Revolution) use Direct3D 9 (`d3d9.dll`, `d3dx9_43.dll`); their COM calls are not traced
  yet (imports are complete).
- Storm 1 loads D3D11 at run time (`LoadLibrary` + `GetProcAddress`), so its creator is found through the
  `GetProcAddress("D3D11CreateDevice")` result.
