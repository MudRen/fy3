// weituo-gun.c -韦陀棍

inherit SKILL;

mapping *action = ({
([	"action":"$N一招「黄石纳履」，手中$w如蜻蜓点水般，招招向$n的下盘要害点去",
	"damage":100,
	"damage_type":"挫伤"
]),
([	"action":"$N把$w平提胸口，一拧身，一招「勒马停锋」，$w猛地撩向$n的颈部",
	"damage":140,
	"damage_type":"挫伤"
]),
([	"action":"$N一招「平地龙飞」，全身滴溜溜地在地上打个大转，举棍向$n的胸腹间戳去",
	"damage":180,
	"damage_type":"挫伤"
]),
([	"action":"$N伏地一个滚翻，一招「伏虎听风」，$w挟呼呼风声迅猛扫向$n的足胫",
	"damage":220,
	"damage_type":"挫伤"
]),
([	"action":"$N一招「流星赶月」，身棍合一，棍端逼成一条直线，流星般向顶向$n的$l",
	"damage":260,
	"damage_type":"挫伤"
]),
([	"action":"$N双手持棍划了个天地大圈，一招「红霞贯日」，一棍从圆心正中击出，撞向$n的胸口",
	"damage":300,
	"damage_type":"挫伤"
]),
([	"action":"$N一招「投鞭断流」，$w高举，以雷霆万钧之势对准$n的天灵当头劈下",
	"damage":340,
	"damage_type":"挫伤"
]),
([	"action":"$N潜运真力，一招「苍龙归海」，$w顿时长了数丈，矫龙般直射$n的胸口",
	"damage":380,
	"damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
                        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练韦陀棍。\n");
	me->receive_damage("kee", 10);
	return 1;
}
