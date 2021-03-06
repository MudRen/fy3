// liuyangstrike.c  天山六阳掌

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「初阳乍升」，双掌一合，左掌护胸，右掌击向$n的$l",
		"dodge":		20,
		"parry":		20,
		"force":		25,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N一招「阳春白雪」，右掌似攻实守，左掌化虚为实击向$n的$l",
		"dodge":		10,
		"parry":		30,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N使出「阳奉阴违」，身形突然消失了，结果却转至$n的背后，一掌拍下",
		"dodge":		50,
		"parry":		-20,
		"force":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N吐气扬声，使出「阳光普照」，双掌化作无数掌影同时向$n的全身攻击",
		"dodge":		-50,
		"parry":		30,
		"force":		50,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N大喝一声，一招「骄阳似火」带起一阵令人窒息的热浪击向$n$l",
		"dodge":		-20,
		"parry":		40,
		"force":		60,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N突然使一招「阴阳怪气」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
		"dodge":		50,
		"parry":		-20,
		"force":		30,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌一错，一招「阳关三叠」对准$n的$l连续拍出三掌",
		"parry":		30,
		"force":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左掌连连画圈，使出一招「夕阳残影」，右掌无声无息地击向$n",
		"dodge":		10,
		"parry":		40,
		"force":		40,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N神色凝重，双掌缓缓地推出，使出「阳歌天钧」，瞬时天地为之一黯",
		"dodge":		-50,
		"parry":		-20,
		"force":		75,
		"damage_type":	"瘀伤"
	]),
});

string *interattack = ({
        "$N双手作掌状，伺机而动。\n",
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}


int valid_learn(object me)
{
	if( (int)me->query_skill("duzun-force", 1) < 20 )
		return notify_fail("你的八荒六合唯我独尊功火候不足，无法领会天山六阳掌。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query_skill("duzun-force", 1) < 20 )
		return notify_fail("你的八荒六合唯我独尊功火候不足，无法领会天山六阳掌。\n");
	if((int)me->query("kee")<30)
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if((int)me->query("force")<10)
		return notify_fail("你的内力不济了，休息一下再练吧。\n");
	 me->receive_damage("kee", 30);
       me->add("force", -10);
	write("你按着所学练了一遍天山六阳掌。\n");
	return 1;
}
