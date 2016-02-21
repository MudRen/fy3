// music yangzhou's 雪莲
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"青龙碧血玉"NOR, ({ "yu","biyu","qinglong" }) );
        set("long", "一块碧玉,上面天然形成一条雪红的飞龙。\n");
        set("unit", "块");
        set("weight", 100);
        set("value", 10000000);
        set("money_id",1);
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("force", (int)ob->query("max_force"));
        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);
        ob->set_temp("windnod",1);
        write("[1;33m你手中的碧玉发出雪红的光茫！\n[0;37m");
        message("vision", HIY + ob->name() + 
"手中的碧玉发出雪红的光,一闪不见！\n"+NOR,
                environment(ob), ob);
        return 1;
}
