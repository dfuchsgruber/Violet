# Data Structures And Pathfinding Audit

The custom containers run without a hosted runtime and generally assume successful allocation. Review zero-capacity construction, multiplication overflow, allocation failure, size/capacity invariants, and empty/singleton behavior.

## Hashmap

Buckets are dynamic arrays. When updating an existing key, return after replacement rather than appending a duplicate. Removal must shift only live entries (`size`), never unused capacity (`array_size`), and must return the removed value consistently even when the bucket becomes empty. Reject or handle a zero bucket count before modulo.

Duplicate keys are especially harmful to A*: a later improved cost/predecessor may be hidden behind the older entry.

## Pathfinding

Audit:

- open-set updates after a lower cost is found;
- predecessor consistency;
- unreachable targets;
- cycles and reconstruction termination;
- destination buffer capacity, including the final STOP byte;
- coordinate packing and signed/unsigned boundaries.

The current reconstruction API does not receive output capacity, while callers commonly reserve 256 bytes. Any safe redesign must thread capacity through all callers or prove a strict path bound below the allocation including the terminator.
