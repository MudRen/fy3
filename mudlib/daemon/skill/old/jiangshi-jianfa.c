// jiangshi-jianfa.c
// 僵尸剑法
// made by cwj 97/7/6

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「死气沉沉」，霎时手中$w尤如一阵阴风压向$n的全身",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出僵尸剑法中的「磷火点点」，顿时剑气罩向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一招「鬼气森森」，身形陡然滑出数尺，手中$w斩向$n的$l",
                "dodge":                -30,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「明珠暗投」对准$n的$l刺出一剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「遮天避日」对准$n的$l斜斜刺出一剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「阎王指路」刺向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「弃明投暗」反手对准$n$l一剑刺去",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上扑，用尽全身劲力一转手中$w使一招「万劫不复」迎面斩向$n的$l",
                "dodge":                -30,
                "parry":                 30,
                 "force":                 75,
                "damage":                50,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
	return notify_fail("你的内力不够，没有办法练僵尸剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "jimie-dafa")
                return notify_fail("僵尸剑法必须配合寂灭大法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword";
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
notify_fail("你的内力或气不够，没有办法练习僵尸剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍僵尸剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("mingjiao")+"/jiangshi-jianfa/"+action;
}
 
