// jinshe-sword.c 金蛇剑法 by ksusan 7/26/97 19:00
// 

inherit SKILL;

string *dodge_msg = ({
        "突然之间，$N身体向后急退丈余，立时又回到了原地，躲过了$N这一招。\n",
        "$n手臂回转，在$N手肘下一推，顺势闪到一旁。\n",
        "$n右手伸出，在$N手腕上迅速无比的一按，顺势跳到一旁。\n",
        "$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
        "$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
	"$N眼睛一花，$n已没了踪影。突然$n从身后拍了一下$N的头，轻轻跃开。\n",
	"$n把剑一横，剑背反射的强光立时刺得$N眼睛一酸，$N竟不知如何是好，停住了攻击。\n",
});

mapping *action = ({
([      "action":"突然之间，$N身体向前急冲丈余，立时又回到了原地，好象根本没有移动过",
        "force" : 80,
        "dodge" : -40,
        "damage": 40,
        "lvl" : 0,
        "skill_name" : "金蛇出洞",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形一顿，冲天而起，剑尖在$n手腕上迅速无比的一点，$n险些击中自己额头",
        "force" : 100,
        "dodge" : -30,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "金蛇吐信",
        "damage_type":  "刺伤"
]),
([      "action":"突然间剑光一闪，$N趁$n的眼睛被$w剑光所迷时猱身而上，蹿到$n的身后，又跃回原地",
        "force" : 120,
        "dodge" : -60,
        "damage": 70,
        "lvl" : 25,
        "skill_name" : "金蛇缠身",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然间招法一变，$w大开大阖，以剑行刀法，招式诡奇绝伦。$n惊骇之中方寸大乱",
        "force" : 140,
        "dodge" : -40,
        "damage": 50,
        "lvl" : 5,
        "skill_name" : "招法一变",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形飘忽，有如鬼魅，左晃右摆，移步到$n的左侧，$n肝胆俱裂",
        "force" : 160,
        "dodge" : -40,
        "damage": 110,
        "lvl" : 10,
        "skill_name" : "有如鬼魅",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
        "force" : 140,
        "dodge" : -5,
        "damage": 120,
        "lvl" : 10,
        "skill_name" : "疾冲上前",
        "damage_type":  "刺伤"
]),
([      "action":"$N喝道：“好！”，便即拔出$w，大力脱手掷出，跟着身形急追而上",
        "force" : 180,
        "dodge" : -30,
        "damage": 70,
        "lvl" : 0,
        "skill_name" : "大力掷出",
        "damage_type":  "刺伤"
]),
([      "action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
        "force" : 200,
        "dodge" : -80,
        "damage": 120,
        "lvl" : 20,
        "skill_name" : "眼前一花",
        "damage_type":  "刺伤"
]),
([      "action":"$N向后疾退，$n紧追两步，突然间$N一个急停，手中$w已指在$n的$l上",
        "force" : 220,
        "dodge" : -10,
        "damage": 60,
        "lvl" : 5,
        "skill_name" : "向后疾退",
        "damage_type":  "刺伤"
]),
([      "action":"$N蓦地冲到$n面前，手中$w直刺$n咽喉！$n慌忙招架，不想$N的$w突然转向",
        "force" : 240,
        "dodge" : 4,
        "damage": 120,
        "lvl" : 45,
        "skill_name" : "直刺咽喉",
        "damage_type":  "刺伤"
]),
([      "action":"$N飞身跃起，$n抬眼一望，但见得$N从天头下脚上直落而下，手中$w刺向$n的$l",
        "force" : 340,
        "dodge" : 20,
        "damage": 95,
        "lvl" : 64,
        "skill_name" : "飞身跃起",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形急转，$n眼前仿佛突然出现了无数个$N，无数把$w一起刺向$n",
        "force" : 380,
        "dodge" : 60,
        "damage": 110,
        "lvl" : 79,
        "skill_name" : "身形急转",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
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
        level   = (int) me->query_skill("jinshe-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[random(i)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
		object ob;
		ob = present("jinshe sword", me);
		if (!ob){
        	return notify_fail("金蛇剑法只能通过研习金蛇剑上的《金蛇密笈》来提高。\n");
		}
		return 1;
}

