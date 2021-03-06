//sougu.c 搜骨鹰爪功

inherit SKILL;

mapping *action = ({
([	"action" : "\n$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「推爪式」",
	"damage":200,
	"damage_type" : "抓伤",
]),
([	"action" : "\n$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「盖爪式」双爪疾向$n脑后击下",
	"damage_type" : "抓伤",
	"damage":140,
]),
([	"action" : "\n$N就地一滚，突然到了$n身前，使一招「掏爪式」，右爪直奔$n小腹",
	"damage_type" : "抓伤",
	"damage":150,
]),
([	"action" : "\n$N左爪护胸，右爪凝劲后发，一招「托爪式」，缓缓托向$n的$l",
	"damage_type" : "抓伤",
	"damage":160,
]),
([	"action" : "\n$N身形诡异，疾速前扑，使一招「撩爪式」，直撩$n裆部",
	"damage_type" : "抓伤",
	"damage":170,
]),
([	"action" : "\n$N身形飘忽，陡然转到$n身后，一招「锁爪式」，双爪直向$n咽喉插下",
	"damage_type" : "抓伤",
	"damage":180,
]),
([	"action" : "\n$N一声厉啸，身形拔起，使出「千爪式」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
	"damage_type" : "抓伤",
	"damage":190,
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object ob, object weapon)
{
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee")<30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force")<20)
		return notify_fail("你的内力不够练鹰爪功。\n");
	me->receive_damage("kee",25);
	me->add("force",-5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sougu/" + action;
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 2;	}

