// fonxansword.c

#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使一招「峰回路转」，单拳化指，如一条银蛇般刺向$n的$l",
		"damage":60,
			"damage_type":  "戳伤"
        ]),
        ([      "action":               
"$N使出慕容拳法中的「空山鸟语」，双拳化掌斩向$n的$l",
		"damage":80,
		"damage_type":  "斩伤"
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，拳掌交加斩向$n的$l",
		"damage":100,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右拳中宫直进，一式「旭日东升」对准$n的$l猛击一拳",
		"damage":	120,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N纵身一跃，拳化指、指变掌，一招「金光泻地」对准$n的$l斜斜劈下",
		"damage":140,
		"damage_type":  "劈伤"
        ]),
        ([      "action":               
"$N的右手凭空一指，一招「童子引路」，拳至半路突变指，急刺$n的$l",
		"damage":	160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N两拳向外一分，使一招「柳暗花明」反手对准$n$l一拳击去",
		"damage":	180,
		"damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双拳护胸，身形一转由拳化掌，使一招「空谷秋虹」拍向$n的$l",
		"damage":	200,
		"damage_type":  "斩伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习慕容拳法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
	write("你按著所学练了一遍慕容拳法。\n");
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"murongquanfa/"+action;
}
void skill_improved(object me)
{
	if(me->query_skill("murongquanfa",1)==20)
	tell_object(me,HIC"你领悟了「探云手」的手法！(tanyunshou)\n"NOR);
	if(me->query_skill("murongquanfa",1)==50)
	tell_object(me,HIC"你领悟了「参合指」的指法！(canhezhi)\n"NOR);
}

int power_point()	{	return 1.5;	}

