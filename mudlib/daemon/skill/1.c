// hannbing-mianzhang.c 寒冰绵掌
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「大江东去」，双掌大开大合，直向$n的$l击去",
	"damage":110,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一变，一式「黄河九曲」，双掌似曲似直，拍向$n的$l",
	"damage":120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「湖光山色」，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
	"damage":130,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两掌一分，一式「曾经沧海」，隐隐发出潮声，向$n横击过去",
	"damage":140,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身形一转，使出一式「水光潋滟」，只见漫天掌影罩住了$n的全身",
	"damage":150,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突然身形一缓，使出一式「小雨初晴」，左掌凝重，右掌轻盈，击往$n的$l",
	"damage":160,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「风雪江山」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
	"damage":170,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「霜华满地」，双掌带着萧瑟的秋气，拍向$n的$l",
	"damage":180,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身法陡然一变，使出一式「仙乡冰舸」，掌影千变万幻，令$n无法躲闪",
	"damage":190,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N清啸一声，一式「冰霜雪雨」，双掌挥舞，如同雪花随风而转，击向$n的$l",
	"damage":200,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" ;
}

int valid_learn(object me)
{
	return 1;
}


mapping query_action(object me, object weapon)
{
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee")<30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 40)
		return notify_fail("你的内力不够练寒冰绵掌。\n");
	me->receive_damage("kee",30);
	me->add("force",-10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang")) > 10 )
	victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang")/10) + 1 + victim->query_condition("ice_poison"));
}

string perform_action_file(string action)
{
	return __DIR__"hanbing-mianzhang/" + action;
}

int power_point()	{	return 1.75;	}
int hard_point()        {       return 3;	}
