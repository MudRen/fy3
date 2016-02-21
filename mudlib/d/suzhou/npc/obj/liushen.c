#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("六神丸",({"liushen wan","wan"}));
      set("unit", "粒");
	set("value",1000);
	set("long","一种用于恢复神的药丸。\n");
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();
      if( living(this_player()) ==0 ) return 0;
   if(!id(arg))
       return notify_fail("你要吃什么？\n");
if ((int)time()-me->query("oldsix_flag/eat_yao")<60)
return notify_fail("你刚吃过补药,连续吃身体受不了.\n");
	me->set("sen",(int)me->query("max_sen"));
	me->set("eff_sen",(int)me->query("max_sen"));
me->set("oldsix_flag/eat_yao",time());
	message_vision("$N吃下一粒六神丸，看起来神色不错。\n",me);
	destruct(this_object());
	return 1;

}
