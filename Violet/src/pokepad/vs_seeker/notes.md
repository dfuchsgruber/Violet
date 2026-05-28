- Daily reset the vs_seeker flags to FALSE with prob p (=potentially retriggerable)
- hash trainer_ids to these flags
- On interaction (in script command for trainerbattle0), if has_vs_seeker and re-triggerable (vs_seeker_flag == FALSE)
    - ask if want to rematch
    - if yes, rematch
- On use: check for persons with trainerid that have flag set to false in visible range, show some animation

Features:
- keep track of rematched trainers, compute level, used skill points
- skill tree-like
- skill-tree features:
    - exp multiplicator on rematches [1.0, 1.2, 1.5, 2.0]
    - ev on rematches [normal, 1/2 prob additional, one additional, double]
    - money on rematches [1.0, 1.2, 1.5, 2.0]
    - likelihood of rematches (prob p) [0.5, 0.6, 0.8, 0.9]




