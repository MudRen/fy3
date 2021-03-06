// xuanyin-strike.c  五毒玄阴掌 by ksusan 7/12/97 7/27/97 10:00
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「青龙吸水」，双掌开合间产生一股强大的气旋，$n身形一窒间$N的双掌已按上了$n的$l",
		"dodge":		-60,
		"parry":		-10,
		"force":		45,
		"damage":		120,
		"damage_type":	"瘀伤",
		"condition_name": "handu",
		"condition_param": 30,
	]),
	([	"action":		"$N一招「金蟾狂鸣」，斗然间一声巨喝，双掌如狂风暴雨般攻向$n的胸膛",
		"dodge":		-20,
		"parry":		-100,
		"force":		80,
		"damage":		150,
		"damage_type":	"瘀伤",
		"condition_name": "handu",
		"condition_param": 40,
	]),
	([	"action":		"$N使出「灵蝎反蜇」，一个筋斗直飞上天，随即头下脚上的直扑$n，在$n封架双掌的时$N的右脚已反踢至$n的后脑",
		"dodge":		-40,
		"parry":		-50,
		"force":		60,
		"damage":		180,
		"damage_type":	"瘀伤",
		"condition_name": "handu",
		"condition_param": 50,
	]),
	([	"action":		"$N身形急转，一招「千蜘万蛛」，刹那间幻出千万个影子，双掌左右合击向$n",
		"dodge":		-50,
		"parry":		-30,
		"force":		90,
		"damage":		200,
		"damage_type":	"瘀伤",
		"condition_name": "handu",
		"condition_param": 60,
	]),
	([	"action":		"$N一声阴笑，使出「百蜈朝仙」，就地一滚直扑入$n的怀中双掌斜撩$n的$l",
		"dodge":		-30,
		"parry":		-20,
		"force":		170,
		"damage":		230,
		"damage_type":	"瘀伤",
		"condition_name": "handu",
		"condition_param": 20,
	]),

});

int valid_learn(object me)
{
        object ob;

		if( (int)me->query_skill("xiuluo-force", 1) < 20 )
			return notify_fail("你的修罗阴煞功火候不足，无法练五毒玄阴掌。\n");
		
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练五毒玄阴掌。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练五毒玄阴掌必须空手。\n");
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
notify_fail("你的内力或气不够，没有办法练习五毒玄阴掌。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍五毒玄阴掌。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/xuanyin-strike/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
                //if( random(me->query_skill("xiuluo-force")) > (damage_bonus + foo)/3 )
	if( random(me->query_skill("xiuluo-force")) > 10) {
		//victim->receive_wound("kee", (damage_bonus + foo));
		victim->apply_condition("xy_poison", random(2) + 1 +
			victim->query_condition("xy_poison"));
	}
}
void skill_improved(object me)
{
        if(me->query_skill("xuanyin-strike",1)==70)       
	       tell_object(me,HIC"你领悟了「隔物传功」的手法！(gewu)\n"NOR);
}