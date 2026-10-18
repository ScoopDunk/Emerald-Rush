EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

@ Used when RUSH_REPEL_PROMPT is on. VAR_ITEM_ID holds the Repel that wore off.
EventScript_RepelWoreOffPrompt::
	lock
	checkitem VAR_ITEM_ID
	goto_if_eq VAR_RESULT, FALSE, EventScript_RepelWoreOffNoneLeft
	msgbox Text_RepelWoreOffUseAnother, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOffRelease
	callnative UseRepelOnField  @ The item task prints "used REPEL" and unlocks the player
	end

EventScript_RepelWoreOffNoneLeft:
	msgbox Text_RepelWoreOff, MSGBOX_DEFAULT
	closemessage
EventScript_RepelWoreOffRelease:
	release
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_RepelWoreOffUseAnother:
	.string "REPEL's effect wore off…\n"
	.string "Use another?$"
