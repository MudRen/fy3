// taiji-dao.c 太极刀
// cleansword 2/15/96
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
	"damage":130,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"damage":140,
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
	"damage":150,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"damage":160,
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
	"damage":170,
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
	"damage":180,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"damage":190,
	"damage_type" : "割伤"
]),
([	"action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
	"damage":200,
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("taiji-quan", 1) < 20)
		return notify_fail("你的太极拳火候太浅。\n");
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
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练太极刀法。\n");
	me->receive_damage("kee", 30);
	return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/wudang/taiji-dao/" + action;
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 2;	}

/*
int parry_action(object me,object target,object target_weapon,int attack_type,mapping action,string limb)
{
	string msg;
	int pp,ap;
	object weapon;
	if( !living(me))	return 0;
	if( !(int)me->query_temp("pfm_tjd"))	return 0;
	weapon=me->query_temp("weapon");
	if( !objectp(weapon) || weapon->query("skill_type")!="blade")
		return 0;
	if( !me->query_skill_mapped("parry") ||
		me->query_skill_mapped("parry")!="taiji-dao")
		return 0;
	if(target_weapon)	ap=target->query_skill(target_weapon->query("skill_type"));
	else	ap=target->query_skill("unarmed");
	pp=me->query_skill("parry");
	if( random(pp)>ap/10)	{
	msg="\n"+action["action"]+"\n";
	msg+=HIW"$n手中"+weapon->query("name")+HIW"划出一层层圆圈，绵绵不绝，将$N的招数尽数挡开！\n"NOR;
	if(target_weapon)
	msg=replace_string(msg,"$w",target_weapon->query("name"));
	msg=replace_string(msg,"$l",limb);
	message_combat(msg,target,me);
	target->start_busy(random(2)+1);
	return 1;
	}
	else return 0;
}

*/
