#include <ansi.h>

inherit KZZNPC;
int do_give();
string query_save_file() { return DATA_DIR + "npc/皇太后"; }

void create()
{
#include <kzznpc.h>
set("inquiry",([
  "四十二章经":(:do_give:),
  ]));
set("book",1);
	setup();
add_money("gold",2);
}
int do_give()
{
  object ob=this_player();
  if (ob->query("banghui")!=query("banghui"))
    return notify_fail("皇太后看了看你,哼了一声.\n");
  if (query("book")!=1)  {
  	command("say 已经给人要走啦,下此要早些来.\n");
  	return 1;
  }
new(__DIR__"obj/42book3.c")->move(ob);
message_vision("$N从衣袖中掏出本书给$n道:要好好保管.\n",this_object(),ob);
set("book",0);
return 1;
}