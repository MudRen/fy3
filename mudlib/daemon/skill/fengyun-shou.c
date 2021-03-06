// fengyun-shou.c -风云手

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「风满长空」，以掌化爪，五指如钩，直逼$n的膻中要穴",
	"damage":60,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚晃，一式「烈火腾云」，右手上下直击，反扣$n的肩井大穴",
	"damage":80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「草深雾泽」，掌指齐出，拍拿并施，拿向$n的三路要害",
	"damage":100,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手鹰抓，右手蛇举，一式「天目昭辉」疾扣$n的中节大脉",
	"damage":120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「雷震四方」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
	"damage":140,
        "damage_type" : "内伤"
]),
([	"action" : "$N两手环扣，全身关节啪啪作响，一式「水到渠成」，击向$n的$l",
	"damage":160,
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「山高林密」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
	"damage":180,
        "damage_type" : "内伤"
]),
([	"action" : "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
	"damage":200,
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

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
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练风云手。\n");
	me->receive_damage("kee", 10);
	me->add("force", -2);
	return 1;
}

