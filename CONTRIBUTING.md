# Contributing

Corrections and new names are welcome, whether it's one function or a thousand. Please read the two rules first.

1. **No game files.** Don't attach or commit executables, game data, Ghidra/IDA/Binary Ninja databases, decompiled
   or disassembled code, or screenshots of it. Names, addresses and a sentence of evidence are all that's needed.
2. **Real names only.** This package carries CyberConnect2's own names, from symbols, the exe's own strings, or
   library and runtime sources. Descriptive guesses (`DoDamageMaybe`) are not accepted, however useful. Keep those
   in your own database.

## The contribution format

Each contribution is one CSV per build, UTF-8, with exactly this header:

```csv
rva,name,confidence,method,src_rva,evidence
0x1a2b30,ccPlayer::UpdateChakra,high,manual,,assert string "ccPlayer::UpdateChakra" at 0x9f1230 references it
0x1a2c90,ccPlayer::Draw,medium,manual,0x83c5a0,same vtable slot as the Switch build's ccPlayer::Draw
0x1a3010,"std::map<int,int>::find",low,manual,,inlined into three callers; signature fits
```

| Column | Content |
|---|---|
| `rva` | Address in hex (`0x…`). PC builds: RVA, i.e. address minus the image base in `meta.json`. Xbox 360: absolute VA. |
| `name` | Fully qualified name, `::`-separated, without `nsN::` Trilogy namespaces. Quote it if it contains commas. |
| `confidence` | `high`, `medium` or `low` (see the policy below) |
| `method` | Lowercase tags: `manual` for hand work. Add others when they apply (`manual+llm-disputed`, or a method from the README's method table). |
| `src_rva` | Optional: the address in the source build you matched against (Switch build, another PC build, …) |
| `evidence` | How you know, in one sentence. Required for high and medium. |

Put the file at `contrib/<game>/<sha256>/<your-handle>.csv`, using the same `<game>/<sha256>` as the build under
`games/`, and check it:

```sh
python tools/validate_contribution.py contrib/storm4/<sha256>/<your-handle>.csv --exe path/to/NSUNS4.exe
```

`--exe` is optional but recommended. It confirms your exe really is that build and that every address is inside
code.

The validator **fails** on:

- a wrong header or bad values;
- the same address with two different names;
- placeholder names (`FUN_…`, `sub_…`);
- a SHA-256 mismatch;
- addresses outside the exe's code.

It **warns** about:

- addresses the package already names differently (conflicts);
- names already used at another address;
- repeated rows;
- high or medium rows without evidence.

Warnings are fine to submit. Explain conflicts in the pull request, because a conflict means one of the two names
is wrong. Open a pull request with the CSV; maintainers merge accepted rows into `functions.csv` on the next
release.

## Confidence policy

| Confidence | Use it when | Applied as |
|---|---|---|
| high | the name is certain: the exe's own string names the function, an exact symbol or export, an exact library-source match, or several independent methods agree | function renamed |
| medium | one strong method, such as a vtable slot, call-graph position, or a unique string shared with a symbol build | renamed, plus comment `[nucc medium <methods>]` |
| low | plausible but unproven; a lead for someone to confirm | comment only: `[nucc low] maybe <name> (<methods>)` |
| `+llm-disputed` (method tag) | an AI review (or you) judged the match doubtful, but it is kept as a lead | always treated as low: comment only, flagged |

If you're unsure, go one level lower. A wrong high-confidence name costs other modders more than a missing one.

## Code changes

Scripts and tools are plain Python 3.8+ (standard library only) and Java (Ghidra). Run the tests before opening a
pull request:

```sh
python -m unittest discover -s tests
```

## Licensing of contributions

By contributing you agree that your data (names, addresses, evidence) is released under CC0 1.0 (LICENSE-DATA),
and your code under the MIT licence (LICENSE).
