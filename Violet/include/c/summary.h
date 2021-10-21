#ifndef H_SUMMARY
#define H_SUMMARY

#include "types.h"

/**
 * Applies a delta to the index of the pokemon currently selected.
 * @param delta the delta to apply
 * @return the new index (or -1 on failure).
 */
s8 summary_selected_party_idx_apply_delta(s8 delta);

/**
 * Applies a delta to the index of the pokemon currently selected, considering the order of multi battles.
 * @param delta the delta to apply
 * @return the new index (or -1 on failure).
 */
s8 summary_selected_party_idx_apply_delta_in_multi_battles(s8 delta);

#endif
