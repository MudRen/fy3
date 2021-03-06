#include <ansi.h>

inherit KZZNPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/温方海"; }
void create()
{
string OBJ_DIR;
#include <kzznpc.h>

        OBJ_DIR="/d/jindezheng/obj";
	set("area_name","景德镇温记老店");
	set("area_file","/d/jindezheng/china-shop.c");
	set("ziyuan","瓷器");
	set("jizhi",80);
	set("kaifa",20);

 set("vendor_goods",([
"guanyin":OBJ_DIR+"/guanyin",
"shuijinpin":OBJ_DIR+"/shuijinpin",
"erping":OBJ_DIR+"/erping",
"haierzheng":OBJ_DIR+"/haierzheng",
"qiankunhu":OBJ_DIR+"/qiankunhu",
  ]));
	setup();
 carry_object(__DIR__"obj/fucloth")->wear();
 carry_object("/obj/weapon/sword")->wield();
}
void init()
{
  object ob;
 ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
   remove_call_out("greeting");
   call_out("greeting",1,ob);
    }
 add_action("do_vendor_list","list");
}
void greeting(object ob)
{
  if (!ob||environment(ob)!=environment()) return;
  switch(random(3))    {
   case 0:
       command("say 欢道光临本店。");
       break;
   case 1:
       command("say 这位"+RANK_D->query_respect(ob)+",本店的瓷器在景德镇首曲一指.\n");
       break;
   case 2:
       command("say 这几天买瓷器的人真多,该让瓷窑多招些人了!\n");
       break;
       }
  return;
}

#include <die.h>