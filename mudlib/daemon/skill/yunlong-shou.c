// yunlongshou.c -云龙手

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「草木皆兵」，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"damage":50,
        "damage_type" : "抓伤"
]),
([	"action" : "在呼呼风声中，$N使一招「捕风捉影」，双手如钩如戢，插向$n的$l",
	"damage":60,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双拳挥舞，一式「浮云去来」，两手环扣，拢成圈状，猛击$n的下颌",
	"damage":70,
        "damage_type" : "内伤"
]),
([	"action" : "$N双手平伸，十指微微上下抖动，一招「十指乾坤」打向$n的$l",
	"damage":80,
	"damage_type" : "内伤"
]),
([	"action" : "$N左手护胸，腋下含空，右手五指如钩，一招「抱残守缺」插向$n的顶门",
	"damage":90,
	"damage_type" : "内伤"
]),
([	"action" : "$N右腿斜插$n二腿之间，一招「掏虚抢珠」，上手取目，下手反勾$n的裆部",
	"damage":100,
	"damage_type" : "内伤"
]),
([	"action" : "$N一手虚指$n的剑诀，一招「空手入刃」，劈空抓向$n手中的兵刃",
	"damage":120,
	"damage_type" : "抓伤"
]),
([	"action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「降龙伏虎」使$n进退两难",
	"damage":140,
	"damage_type" : "内伤"
]),
([	"action" : "$N一手顶天成爪，一手指地，一招「拨云见日」,劲气笼罩$n的全身",
	"damage":160,
	"damage_type" : "内伤"
]),
([	"action" : "$N一式「如烟往事」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"damage":180,
        "damage_type" : "内伤"
]),
([	"action" : "$N随意挥洒，使一式「我心依旧」，掌心微红,徐徐拍向$n的$l",
	"damage":200,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练云龙手必须空手。\n");
	return 1;
}


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}


int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练云龙手。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-shou/" + action;
}

int power_point()	{	return 1.25;	}

