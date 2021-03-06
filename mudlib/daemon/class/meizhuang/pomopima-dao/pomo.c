//pomopima-dao, perform pomo
//by tianson
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int pomo,times;
        string shu;
        pomo = (int)me->query_skill("pomopima-dao", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「泼墨九刀」？\n");

        if(!me->is_fighting())
                return notify_fail("「泼墨九刀」只能在战斗中使用！\n");
         
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="blade")
                return notify_fail("「泼墨九刀」要用刀才能发挥威力。\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("你的精神不足，没法子施展泼墨九刀！\n");

        if(pomo < 40)
                return notify_fail("你的泼墨披麻刀级别还不够。\n");
        else 
            if(pomo <70){
                times = 3;        
                shu = "三";}
            else
                if (pomo <100){
                    times = 4;
                    shu = "四";}
                else 
                    if( pomo<130){
                        times = 5;
                        shu = "五";}
                    else
                        if(pomo <160 ){
                           times = 6;
                           shu = "六";}
                        else 
                            if (pomo < 190){
                               times = 7;
                               shu = "七";}
                            else
                                if (pomo < 220){
                                    times = 8;
                                    shu = "八";}
                                else{ 
                                     times = 9;
                                     shu = "九";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");


message_vision(HIC"\n$N一声长啸，刀光一转，闪电般连续向$n劈出了"+shu+"刀，刀刀要命！\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        
        me->receive_damage("sen", 20);
        me->add("force", -(times*50+150));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}

