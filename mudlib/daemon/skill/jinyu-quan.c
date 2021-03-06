// jinyu-quan.c 金玉拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N一招「金光灿烂」，双拳一上一下, 向$n挥去",
	"damage":50,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「其利断金」，幻出一片拳影，气势如虹，击向$n的头部",
	"damage":80,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N身影向上飘起，脸浮微笑，一招「蓝田美玉」，轻轻拍向$n的$l",
	"damage":110,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「金玉其外」，双拳一合，$n只觉到处是$N的拳影",
	"damage":140,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招
「金玉满堂」",
	"damaeg":170,
	"damage_type" : "瘀伤"
]),
([	"action" : "只见$N一个侧身退步，左手虚晃，突然猛跨两步，已到$n面前，
右拳陡出，事先绝无征兆，迅如崩雷，一招「点石成金」击向$n的前胸",
	"damage":200,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「众口铄金」，扑向$n，似乎$n的全身都被拳影笼罩",
	"damage":220,
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry";}


int valid_learn(object me)
{
    if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法练金玉拳。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金玉拳必须空手。\n");
	if((int)me->query("max_force")<100)
		return notify_fail("你的内力太弱，无法练金玉拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if((int)me->query("kee")<50)
		return notify_fail("你的体力太低了。\n");
	if((int)me->query("force")<20)
		return notify_fail("你的内力不够练金玉拳。\n");
	me->receive_damage("kee",30);
	me->add("force",-10);
	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


