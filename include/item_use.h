#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

// VAR_REPEL_STEP_COUNT layout. With RUSH_REPEL_PROMPT the low byte is the steps
// left and the high byte is the Repel item that was used.
#if RUSH_REPEL_PROMPT
#define REPEL_STEPS(var)            ((var) & 0xFF)
#define REPEL_ITEM(var)             ((var) >> 8)
#define REPEL_VAR(item, steps)      (((item) << 8) | ((steps) & 0xFF))
#else
#define REPEL_STEPS(var)            (var)
#define REPEL_VAR(item, steps)      (steps)
#endif

void UseRepelOnField(void);

void ItemUseOutOfBattle_Mail(u8 taskId);
void ItemUseOutOfBattle_Bike(u8 taskId);
void ItemUseOutOfBattle_Rod(u8 taskId);
void ItemUseOutOfBattle_Itemfinder(u8 var);
void ItemUseOutOfBattle_PokeblockCase(u8 taskId);
void ItemUseOutOfBattle_CoinCase(u8 taskId);
void ItemUseOutOfBattle_PowderJar(u8 taskId);
void ItemUseOutOfBattle_WailmerPail(u8 taskId);
void ItemUseOutOfBattle_Medicine(u8 taskId);
void ItemUseOutOfBattle_ReduceEV(u8 taskId);
void ItemUseOutOfBattle_SacredAsh(u8 taskId);
void ItemUseOutOfBattle_PPRecovery(u8 taskId);
void ItemUseOutOfBattle_PPUp(u8 taskId);
void ItemUseOutOfBattle_RareCandy(u8 taskId);
void ItemUseOutOfBattle_TMHM(u8 taskId);
void ItemUseOutOfBattle_Repel(u8 taskId);
void ItemUseOutOfBattle_EscapeRope(u8 taskId);
void ItemUseOutOfBattle_BlackWhiteFlute(u8 taskId);
void ItemUseOutOfBattle_EvolutionStone(u8 taskId);
void ItemUseOutOfBattle_Berry(u8 taskId);
void ItemUseOutOfBattle_EnigmaBerry(u8 taskId);
void ItemUseOutOfBattle_CannotUse(u8 taskId);
void ItemUseInBattle_PokeBall(u8 taskId);
void ItemUseInBattle_StatIncrease(u8 taskId);
void ItemUseInBattle_Medicine(u8 taskId);
void ItemUseInBattle_PPRecovery(u8 taskId);
void ItemUseInBattle_Escape(u8 taskId);
void ItemUseInBattle_EnigmaBerry(u8 taskId);
void Task_UseDigEscapeRopeOnField(u8 taskId);
bool8 CanUseDigOrEscapeRopeOnCurMap(void);
u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);

enum ItemTMHMOrEvolutionStone
{
    ITEM_IS_OTHER,
    ITEM_IS_TM_HM,
    ITEM_IS_EVOLUTION_STONE,
};

#endif // GUARD_ITEM_USE_H
