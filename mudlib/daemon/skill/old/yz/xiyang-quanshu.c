// fonxansword.c

#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N左手护面，右手「直拳」快如闪电，直奔$n的$l而来",
			"dodge":                30,
		"damage":               50,
		"parry":		50,
		"damage_type":"瘀伤"
        ]),
        ([      "action":               
"$N双腿微屈，眼中精光一闪，右拳划出道弧线击向$n的$l",
		"dodge":                40,
		"damage":               50,
		"parry":		40,
		"force":		40,
	"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N大喝一声，右手一记「重拳」夹着呼呼风声直扑$n的$l",
		"dodge":		40,
		"damage":               50,
		"parry":		40,
		"force":		40,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身体微倾，左臂内收，使出「摆拳」，对着$n的$l猛击过去",
		"dodge":		40,
		"parry":		60,
		"force":		30,
		"damage":		80,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N施展「刺拳」，双拳快似流星，对着$n的$l连击数下",
		"dodge":		40,
		"parry":		80,
		"force":		70,
		"damage":		90,
	"damage_type":  "击伤"
        ]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
