#include <ansi.h>

int exert(object me)
{       
        int nh, improve;
        nh = (int)me->query_skill("emei-xinfa");
        improve = nh * 3 / 2;
        if( me->is_fighting() )
                return notify_fail("战斗中运功？找死吗？\n");

        if (me->is_busy() )
        return notify_fail("你正忙着哪！\n");

        if ((int)me->query_skill("emei-xinfa", 1) < 150)
                return notify_fail("你的峨眉心法修为还不够。\n");

        if( (int)me->query("force") < 150 )
                return notify_fail("你的真气不够。\n");
        
      if( me->query_temp("yun_yinyang")   )
                return notify_fail("你正在运用峨眉心法的「阴阳」字决！\n");
        write(HIW"你暗运阴阳两庄，吸取阴阳两气，聚精成力，顿觉气力倍增。\n"NOR, me);

        message_vision(HIW"只见$N稍显疲乏，但转瞬间便精神抖擞。\n"NOR,me);

        me->add("eff_sen", improve );
        me->add("sen", improve);
        me->add("eff_gin", improve);
        me->add("gin", improve);
        me->add("max_kee", improve);
        me->add("kee", improve);
        me->set_temp("yun_yinyang", 1);  
        me->add("force", - 150);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2);
        return 1;
}
void remove_effect(object me, int improve)
{
      me->add("eff_gin", - improve);
      me->add("max_kee", - improve);
      me->add("eff_sen", - improve);
      me->delete_temp("yun_yinyang");
 tell_object(me, HIR"你的峨眉心法「阴阳」字决运功完毕，看起来你脸色好多了。\n"NOR);
}
