# Injection Audit Checklist

- Build or obtain the exact base ROM configured in `.env`.
- Disassemble every patched range and all incoming branches.
- Detect overlapping written byte ranges across included patch files.
- Verify function versus data pointer Thumb state.
- Verify wrapper stack balance, alignment, saved registers, and stack arguments.
- Verify displaced instructions and continuation addresses.
- Check condition flags if original control flow consumed them.
- Check literal pools do not overwrite adjacent code/data and remain reachable.
- Match every table repoint to consumer element width, count, sentinel, and index range.
- Trace hook allocation, initialization, normal teardown, cancellation, and abnormal exits.
- Check all NOLOAD EWRAM reads are dominated by initialization.
- Inspect linked sections for discarded writable state.
- Verify overlay end, final ROM size, and EWRAM usage.
- Build both supported languages when strings or preprocessed control flow differ.
- Re-run focused object builds with warnings-as-errors and the full ROM build.
