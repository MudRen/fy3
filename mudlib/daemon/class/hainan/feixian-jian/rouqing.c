#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,mk,ms,mp,yk,ys,yp;
        object weapon;
        extra = me->query_skill("feixian-jian",1);
        if ( extra < 80) return notify_fail("你的飞仙剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［柔情冷魅］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("使用「柔情冷魅」必须拿着一把剑！\n");
        if ((int)me->query("force")<150)
                return notify_fail("你的内力不够。\n"); 
        me->add("force",-150);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$N使出飞仙剑法中的绝招［柔情冷魅］，一招连环八剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
//      if (random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 ) 
        mk=me->query("kar");
        ms=me->query("spi");
        mp=me->query("per");
        yk=target->query("kar");
        ys=target->query("spi");
        yp=target->query("per");
        if (random((mk)+ms+mp) * me->query("combat_exp") > (yk+ys+yp)*me->query("combat_exp"))
        {
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon);
        COMBAT_D->do_attack(me,target, weapon); 
        COMBAT_D->do_attack(me,target, weapon);         
        
        message_vision(WHT"$N连出八剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
        me->start_busy(5);
        } else { 
                message_vision(HIC"可是$n看破了$N的招式,趁机发动进攻！\n" NOR,me,target);
                me->start_busy(3);
        }        
        return 1;
}

