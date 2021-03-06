// yunlong-zhua.c -凝血神爪

inherit SKILL;

mapping *action = ({
([	"action" : "$N全身拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
	"damage":60,
	"damage_type" : "抓伤"
]),
([	"action" : "$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪一前一后拢向$n的$l",
	"damage":80,
        "damage_type" : "抓伤"
]),
([	"action" : "$N一式「拔翅鹰飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
	"damage":100,
        "damage_type" : "内伤"
]),
([	"action" : "$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
	"damage":120,
        "damage_type" : "内伤"
]),
([	"action" : "$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
	"damage":140,
        "damage_type" : "内伤"
]),
([	"action" : "$N伏地滑行，一式「顶天立地」，上手袭向膻中大穴，下手反抓$n的裆部",
	"damage":160,
        "damage_type" : "内伤"
]),
([	"action" : "$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
	"damage":180,
        "damage_type" : "内伤"
]),
([	"action" : "$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
	"damage":200,
        "damage_type" : "内伤"
]),
([	"action" : "$N忽的拨地而起，使一式「苍龙出水」，身形化作一道闪电射向$n",
	"damage":210,
        "damage_type" : "内伤"
]),
([	"action" : "$N微微一笑，使一式「万佛朝宗」，双手幻出万道金光,直射向$n的$l",
	"damage":220,
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练凝血神爪必须空手。\n");
	if ((int)me->query_skill("yunlong-xinfa",1)<50)
		return notify_fail("你的云龙心法火候不够，无法学凝血神爪。\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学凝血神爪。\n");
	if ((int)me->query("max_force") < 350)
		return notify_fail("你的内力太弱，无法练凝血神爪。\n");
	if ((int)me->query_skill("unarmed",1) <40)
		return notify_fail("你的基本搏击火候不够，无法学凝血神爪。\n");
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
		return notify_fail("你的内力不够练凝血神爪。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(me->query_skill("yunlong-xinfa")>70)	{
	if( random(me->query_skill("ningxue-shenzhua"))>30){
            victim->apply_condition("zhua_poison", random(me->query_skill("ningxue-shenzhua")/10) + 1 +
			victim->query_condition("zhua_poison"));
	}
	}
}

string perform_action_file(string action)
{
	return __DIR__"ningxue-shenzhua/"+action;
}

int power_point()	{	return 1.75;	}
int hard_point()	{	return 2;	}

