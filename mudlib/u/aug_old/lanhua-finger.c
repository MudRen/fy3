// lanhua-finger.c  兰花拂穴手
// 97.9.27 by Aug

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「中流砥柱」，一指石柱般指向$n的$l",
		"dodge":		30,
		"parry":		20,
		"force":		40,
		"damage":		60,
		"lvl":		0,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一式「风花雪月」使出，手指想飘花般散开，$n顿时被包围在指力之中。",
		"dodge":		50,
		"parry":		60,
		"force":		100,
		"damage":		100,
		"lvl":		9,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N的手指想影子般追逐着$n的身形，「枝附影从」,$n再也摆脱不掉$N的手指。",
		"dodge":		80,
		"parry":		80,
		"force":		110,
		"damage":		110,
		"lvl":		19,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「兰摧玉折」，手指如兰花般的拂向$n的$l",
		"dodge":		-50,
		"parry":		-20,
		"force":		200,
		"damage":		200,
		"lvl":		29,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「玉石俱焚」，天地为之一暗，$N似乎拼命似的戳向$n的$l",
		"dodge":		-60,
		"parry":		-80,
		"force":		260,
		"damage":		300,
		"lvl":		39,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「月残花缺」使出，$n的面前出现了无数花影，美的让人心碎，顿时忘了防御",
		"dodge":		150,
		"parry":		150,
		"force":		250,
		"damage":		250,
		"lvl":		49,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N身形一展跃在空中，「凤舞九天」居高临下一指戳向$n的$l",
		"dodge":		150,
		"parry":		150,
		"force":		280,
		"damage":		280,
		"lvl":		59,
		"damage_type":	"瘀伤"
	]),	
	([	"action":		"$N一招「弹指惊雷」，天地间一道闪电击向$n的$l",
		"dodge":		100,
		"parry":		100,
		"force":		400,
		"damage":		400,
		"lvl":		79,
		"damage_type":	"瘀伤"
	]),


});

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练兰花拂穴手必须空手。\n");
	if( (int)me->query_skill("suiyu-force", 1) < 10 )
		return notify_fail("你的碎玉神功火候不足，无法练兰花拂穴手。\n");
	if( (int)me->query_skill("unarmed", 1) < 10 )
		return notify_fail("你的徒手搏击火候不足，无法练兰花拂穴手。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习兰花拂穴手。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍兰花拂穴手。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/lanhua-finger/" + action;
}

void skill_improved(object me)
{
        if(me->query_skill("lanhua-finger",1)==60)       
	       tell_object(me,HIC"你领悟了「弹指神通」的手法！(tanzhi)\n"NOR);
}