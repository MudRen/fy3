//玄天指

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage,ap,dp;
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("玄天指只能对战斗中的对手使用。\n");

		
	if( (int)me->query_skill("xuantian-quan",1)<20)
	return notify_fail("你的玄天拳法不够娴熟，不会使用「玄天指」。\n");
	if( (int)me->query_skill("xuantian-neigong",1)<20)
	return notify_fail("你的玄天内功功力不够，不能使用「玄天指」。\n");
	if( (int)me->query("force")<100)
	 return notify_fail("你现在内力太弱，不能使用「玄天指」。\n");
	if(me->query("kee")<50)
	return notify_fail("你现在气不足，无法使用「玄天指」。\n");
	if(weapon=target->query_temp("weapon"))
	msg=CYN"$N脸上精光大盛，突然伸出右手向$n的"+weapon->name()+"夹去！\n"NOR;
	else msg=CYN"$N大喝一声，右手食指向着$n的胸口点去！\n"NOR;
	ap=me->query_skill("unarmed")+me->query_skill("dodge");
	dp=target->query_skill("parry")+target->query_skill("dodge");
	if(random(ap)>random(dp))	{
	me->start_busy(3);
		target->start_busy(random(3));
	if(weapon)	{
	msg+=RED"只听得“卡嗒”一声，$n手中的"+weapon->name()+"已断为两截！\n"NOR;
	weapon->move(environment(target));
	weapon->set("name","断了的"+weapon->query("name"));
	weapon->unequip();
	weapon->set("value",weapon->query("value")/10);
	weapon->set("weapon_prop", 0);
	target->reset_action();
	}
	else	{
	msg+=RED"只听“噗”的一声，$n的胸口被$N戳了个小孔！\n"NOR;
	damage=(me->query_str()-target->query_con())*random(me->query_cor());
	if(damage<0)	damage=10;
	target->receive_damage("kee",damage);
        target->receive_wound("kee",damage/3);
	}
	me->add("force",-random(10));
	} else 
		{
		me->start_busy(1);
	me->add("force",-5);
		msg += CYN"可是$p看破了$P的企图，身形一晃闪了开去。\n"NOR;
		}
	message_vision(msg, me, target);

	return 1;
}
