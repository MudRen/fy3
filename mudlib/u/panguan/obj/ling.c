// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
}

void create()
{
        set_name("孔雀翎", ({ "kongque ling", "ling" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("bullet", 3);
                set("value", 0);
                set("material", "steel");
      set("long", "这就是江湖中传言的见血封喉的孔雀翎,里面有三只飞镖。可以用(aim)瞄准,用(shoot)发射.\n");
                set("wield_msg", "$N从腰边的口袋里掏出一支$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n放回腰间的口袋里。\n");
        }
        init_blade(100);
        setup();
}

int do_aim(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("飞镖已经用完了。\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");

        message_vision(HIY "\n$N举起孔雀翎，远远地瞄准$n。\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_shoot()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("你还没有瞄准你的射击目标！\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("你要射击的对象已经离开了。\n");

        message_vision(HIR "\n$N对准$n发出了孔雀翎！！！\n只听$n惨叫一声，缓缓地仆倒在血泊里！\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
        obj->die();

        return 1;
}


