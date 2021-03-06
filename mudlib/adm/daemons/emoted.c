// emoted.c

// music 12.13

#include <ansi.h>

inherit F_SAVE;

mapping emote;

//	The emote mapping contains the data base of emote definitions. Each emote
//	is defined in a sub-mapping with the following structure:
//
//	myself	- the message emoter will see
//	target	- the message the target will see when targeted
//	others	- the message others will see when no argument.
//
//	The emote mapping is indexed with the emote 'pattern' instead of emote
//	verb. For example, typing "smile" without argument will cause the daemon
//	search the emote mapping with "smile" as key, and typing "smile someone"
//	will cause the daemon search the emote mapping with "smile $" pattern as
//	the key, while $ means one argument.
//
//	In the message string, the following substitutions will be applied before
//	sending the messages:
//
//	$N		- name of emoter 作动作的人的名字
//	$n		- name of target 目标的名字
//	$P		- pronoun of emoter 作动作的人的代称
//	$p		- pronoun of target 目标的的代称
//	$S		- 对自己的尊称 query_self
//	$s		- 对自己的贱称 query_self_rude
//	$C		- 对自己的辈分关系
//	$c		- 对别人的辈分关系
//	$R		- 对别人的尊称 query_resprct
//	$r		- 对别人的贱称 query_resprct_rude
//
//	Original by Annihilator@ESII (11/09/94)

void create()
{
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
int do_emote(object me, string verb, string arg)
{
	string str, my_gender, target_gender, msg_postfix;
	object target;
	string arg1;
	int chat_flag, rumor_flag;
        if(verb !=0) verb = lower_case(verb);
        if(arg !=0) arg = lower_case(arg);

	if( !environment(me) ) return 0;
	if( (int)me->query("bad_chat"))
		return notify_fail("你的聊天权力已被关闭。\n");

	chat_flag = 0;
	if ((verb == "chat*" && arg != 0)) {
        	if (sscanf(arg , "%s %s", verb, arg1)==0) 
         	       verb = arg;
		arg = arg1;
		chat_flag = 1;
	}

	rumor_flag = 0;
        if ((verb == "rumor*" && arg != 0)) {
                if (sscanf(arg , "%s %s", verb, arg1)==0) 
                       verb = arg;
                arg = arg1;
                rumor_flag = 1;
        }

	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

	
	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != 0 ) {
	        target = present(arg, environment(me));
	        if(chat_flag || rumor_flag)
	         {if(!objectp(target)) target = find_player(arg);
	          if(!objectp(target)) target = find_living(arg);
	          if(!objectp(target)) return notify_fail("哪儿有"+ arg + "？\n");
	         }
		if(!objectp(target)) return 0;
//                if( !target->is_character() )
//                        return notify_fail("你要对谁做这个动作？\n");
		target_gender = target->query("gender");
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

	my_gender = me->query("gender");

	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		if (!rumor_flag)
			str = replace_string(str, "$N", me->name());
		else 
			str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$S", RANK_D->query_self(me));
		if( objectp(target) ) {
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
			str = replace_string(str, "$C", RANK_D->query_guanxi(me,target)+"我");
                        str = replace_string(str, "$c", RANK_D->query_self_guanxi(me,target));
		}
		if(!chat_flag && !rumor_flag)
		message("emote", CYN + str + NOR, me);
	}
	if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
                if (!rumor_flag)
			str = replace_string(str, "$N", me->name());
                else 
                        str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_pronoun(my_gender));
		str = replace_string(str, "$n", target->name());
		str = replace_string(str, "$p", gender_self(target_gender));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$c", RANK_D->query_self_guanxi(me,target));
                str = replace_string(str, "$C", RANK_D->query_guanxi(me,target)+"我");

		if(!chat_flag && !rumor_flag)
		message("emote", CYN + str + NOR, target);
	}
	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
                if (!rumor_flag)
			str = replace_string(str, "$N", me->name());
                else 
                        str = replace_string(str, "$N", "某人");
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$S", RANK_D->query_self(me));

		if( objectp(target) ) {
			str = replace_string(str, "$n", target->name());
			str = replace_string(str, "$p", gender_pronoun(target_gender));
                        str = replace_string(str, "$r", RANK_D->query_rude(target));
                        str = replace_string(str, "$R", RANK_D->query_respect(target));
                        str = replace_string(str, "$c", RANK_D->query_self_guanxi(me,target));
	                str = replace_string(str, "$C", RANK_D->query_guanxi(me,target)+"我");

		}
		if (!chat_flag && !rumor_flag)
		message("emote", CYN + str + NOR, environment(me), ({me, target}));
		else if (chat_flag){

message("channel:chat", HIC +"【闲聊】"+ str + NOR, users());
//  message("channel:sys",HIG+"〖监控精灵】("+me->query("id")+")"+str+NOR,users());
        

		} else {
			message("channel:rumor", YEL +"【谣言】"+ str + NOR, users());
			message("channel:sys",  HIM +"【谣言精灵】("+me->name()+")"+str 
+ NOR, users());
		
		}
	}

	if( objectp(target) ) target->relay_emote(me, verb);

	return 1;
}

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}
