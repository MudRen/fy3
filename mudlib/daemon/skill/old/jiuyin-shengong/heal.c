// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("jiuyin-shengong", 1) < 20)
                return notify_fail("你的九阴神功修为还不够。\n");
        if( (int)me->query("force") < 50 ) // - (int)me->query("max_force") < 50 )
                return notify_fail("你的真气不够。\n");
       
       if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
              return notify_fail("你现在没有受任何伤。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你全身放松，运起九阴神功,按九阴真经的方法为自己疗伤。\n" NOR);
        message("vision",
                BLU + me->name() + "坐下来开始运起九阴神功疗伤,忽然吐出一口瘀血，脸色看起来好多了。\n" NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}
