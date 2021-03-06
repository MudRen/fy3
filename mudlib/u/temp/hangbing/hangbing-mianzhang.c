// hannbing-mianzhang.c 寒冰绵掌
inherit SKILL;
mapping *action = ({
([      "action" : "$N身法陡然一变，使出一式「仙乡冰舸」，掌影千变万幻，令$n无法躲闪",
        "dodge": 20,
        "force": 100,
      "poison": 20,
        "damage_type": "瘀伤"
]),
([      "action" : "$N临空一飞，拔地而起，将手中的$w往$n的$l猛击过去,$n顿时方寸打乱，好一个[落花式]",
        "dodge": 30,
        "force": 120,
      "poison": 30,
        "damage_type": "瘀伤"
]),
([      "action" : "$N使一式「湖光山色」，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
        "dodge": 40,
        "force": 130,
      "poison": 50,
        "damage_type": "瘀伤"
]),
([      "action" : "$N两掌一分，一式「曾经沧海」，隐隐发出潮声，向$n横击过去",
        "dodge": 50,
        "force": 240,
      "poison": 70,
        "damage_type": "瘀伤"
]),
([      "action" : "$N身形一转，使出一式「水光潋滟」，只见漫天掌影罩住了$n的全身",
        "dodge": 60,
        "force": 150,
      "poison": 90,
        "damage_type": "瘀伤"
]),
([      "action" : "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "dodge": 50,
        "force": 160,
      "poison": 80,
        "damage_type": "瘀伤"
]),
([      "action" : "$N使一式「风雪江山」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
        "dodge": 80,
        "force": 160,
      "poison": 90,
        "damage_type": "瘀伤"
]),
([      "action" : "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge": 90,
        "force": 230,
      "poison": 100,
        "damage_type": "瘀伤"
]),
([      "action" : "$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
        "dodge": 100,
        "force": 100,
      "poison": 100,
        "damage_type": "瘀伤"
]),
([      "action" : "$N双掌挟着一股腥臭之气拍向$n的$l",
        "dodge": 100,
        "force": 100,
      "poison": 120,
        "damage_type": "瘀伤"
])
});

int valid_enable(string usage)
{
        return usage=="strike" || usage=="parry" ;
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练寒冰绵掌必须空手。\n");
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候不够，无法学寒冰绵掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够练寒冰绵掌。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang")) > 10 )
        victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang")/8) + 1 + victim->query_condition("ice_poison"));
}

string perform_action_file(string action)
{
        return __DIR__"hanbing-mianzhang/" + action;
}

