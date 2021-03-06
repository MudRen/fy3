// jiugong-strike 
// 九宫神行掌

inherit SKILL;

mapping *action = ({
	([	"action":		"$N怒吼一声，横身一跃，右掌「直劈华山」，用足十成力量向$n的$l就是一掌",
		"dodge":		20,
		"parry":		20,
		"force":		25,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N右掌一立，左掌「银虹疾吐」，攸的便向$n的$l挑来",
		"dodge":		10,
		"parry":		30,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N右掌辟面扶来，左手骈指如戟，一招「顺手牵羊」，点向$n的$l，",
		"dodge":		50,
		"parry":		-20,
		"force":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌疾发，一记「弯弓射雕」，一前一后向$n的$l击来",
		"dodge":		-50,
		"parry":		30,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌一拂，身随掌走，左掌一拨，右掌「斜摆单鞭」便向$n的$l切下",
		"dodge":		-20,
		"parry":		40,
		"force":		60,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N突然攸地一分，斜身上步，右掌横挡，左掌一翻，一招「孔雀抖屏」，向$n的$l一撩",
		"dodge":		50,
		"parry":		-20,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一探身，举腿横扫，接着右掌一式「牵缘手」对准$n的$l劈下",
		"parry":		30,
            "dodge":          45,
		"force":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一翻右掌，一招「拨云见日」，无声无息地击向$n的$l",
		"dodge":		10,
		"parry":		40,
		"force":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N突然沉掌横截，一记「手挥琵琶」，向$n的$l截来",
		"dodge":		-50,
		"parry":		-20,
		"force":		75,
		"damage_type":	"瘀伤"
	]),
       ([	"action":	"$N右脚往后一蹲，右臂一沉，左臂一立，一式「举火撩天」，向$n的$l劈来",
		"dodge":		-50,
		"parry":		-20,
		"force":		75,
		"damage_type":	"瘀伤"
	]),
});
int valid_learn(object me)
{
        object ob;

                if( (int)me->query_skill("xiantian-force", 1) < 20 )
                return notify_fail("你的先天气功火候不足，无法练九宫神行掌
。\n");

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练九宫神行掌
。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练九宫神行掌必须空手。\n");
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
notify_fail("你的内力或气不够，没有办法练习九宫神行掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍九宫神行掌。\n");
        return 1;
}

