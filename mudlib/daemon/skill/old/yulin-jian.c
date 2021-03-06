inherit SKILL;
mapping *action = ({
    ([
      "action":
"$N手腕一抖，$w剑尖化为五道白光，分别向$n的咽喉、左右肩、和左右脚腕疾刺",
      "dodge":		0,
      "parry":	        0,
      "damage":		20,
      "damage_type":	"刺伤",
      "name":		"「手挥五弦」",
      ]),
    ([
      "action":
"$N脚下步步生莲，手中$w在身前一划,一片扇形白光向$n扑去。\n"
"$n识得这招「轻罗小扇」的威力，连忙躲避不迭",
      "dodge":		10,
      "parry":		-20,
      "damage":		30,
      "damage_type":	"割伤",
      "name":		"「轻罗小扇」",
      ]),
    ([
      "action":
"$N纵身跃起，手中$w带起万道银光，向$n的面门点去。\n"
"这招「乱洒星罗」果然把$n逼得手忙脚乱",
      "dodge":		5,
      "parry":	       -10,
      "damage":		20,
      "damage_type":	"刺伤",
      "name": 		"「乱洒星罗」",
      ]),
	
    ([
      "action":
"$N身如被狂风所吹,裙裾飘飘，手中$w向$n轻点数下！\n"
"这招「姑射仙人」玄妙非常，大有仙气,$n简直惊呆了",
      "dodge":		5,
      "parry":	        -5,
      "damage":		30,
      "damage_type":	"刺伤",
      "name": 		"「姑射仙人」",
      ]),
    ([
      "action":
"$N长袖飘舞,身形急转,转眼间就成了一片白雾。一道剑光从白雾中击向$n!\n"
"这招「月下轻舞」先保己,后伤敌,已立于不败之地",
      "dodge":		10,
      "parry":	        -10,
      "damage":		35,
      "damage_type":	"刺伤",
      "name": 		"「月下轻舞」",
      ]),
    ([
      "action":
"$N身随剑走，迅速无伦地在$n周围布下一道剑网。\n"
"$n只见周围无数人影，随时都有可能有一柄$w从意想不到的\n"
"位置刺来，实在是危机重重",
      "dodge":	       0,
      "parry":		-15,
      "damage":		15,
      "damage_type":	"刺伤",
      "name": 		"「花间轻酌」",
      ]),
});

int valid_learn(object me)
{
    object ob;
    
    if (me->query("family/family_name") != "海南白云庵")
	return notify_fail("你不是白云庵传人,无法修习这种玄妙剑法。\n");
    if ((int)me->query("max_force") < 100)
	return notify_fail("你的真气不足，难以领悟剑法的精妙之处。\n");
    
    if (!(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
	return notify_fail("你必须先找一把剑才能练剑法。\n");
    
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if (me->query("family/family_name") != "海南白云庵")
	return notify_fail("你不是白云庵弟子,无法修习这种武功。\n");
    if ((int)me->query("kee") < 30)
	return notify_fail("你的气太低，再练下去会有危险的！\n");
    if ((int)me->query("force") < 5)
	return notify_fail("你的内力不够，没有办法运用玉灵剑法。\n");
    me->receive_damage("kee", 30);
	me->add("force", -5);
    write("你按著所学练了一遍玉灵剑法。\n");
    return 1;
}
