#include <ansi.h>
inherit NPC;
int ask_jiaru();
int re_rank(object ob);
string check_player(object ob);
void create()
{
        set_name("李沉舟", ({ "li","li chengzhou"}));
            set("gender", "男性" );
        set("title","权力帮帮主");
        set("age", 25+random(10));
        set("banghui","权力帮");
        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        set("inquiry",([
                  "入帮":(:ask_jiaru:),
                  "加入":(:ask_jiaru:),
                  "jiaru":(:ask_jiaru:),
                  "join":(:ask_jiaru:),
                  "权力帮":"我权力帮人多势众,掌握天下!\n",
                                "rank":(:re_rank:),
        ]));
  enable_commands();
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 30+random(20));
}
void init()
{
   object ob;
   ::init();
  if (interactive(ob=this_player())&&!is_fighting())      {
       remove_call_out("greeting");
       call_out("greeting",1,ob);
    }
}
void greeting(object ob)
{
   if (ob->query("banghui")!=this_object()->query("banghui"))   {
        command("say 这位"+RANK_D->query_respect(ob)+",有意加入我帮么?\n");
        return;
        }
  command("say "+ob->query("name")+",过来,过来!\n");
   re_rank(ob);
   return;
}
int ask_jiaru()
{
    object ob,me;
  me=this_object();
  ob=this_player();
if (ob->query("banghui")==me->query("banghui"))    {
   command("say 我们早就是一帮的啦,开什么玩笑!\n");
  return 1;
        }
if (ob->query("banghui"))
     {   command("say 等你脱离原来的帮会再说!\n");
         return 1;
      }   
                    command("say 请用jiaru li来加入权力帮!\n");
           command("yaoqing "+ob->query("id"));
  return 1;
}
int re_rank(object me)
{ 
   string rank,old_rank;
   me=this_player();
  if (me->query("banghui")!="权力帮")    return notify_fail("你又不是权力帮中人.\n");
   rank=check_player(me);
   old_rank=me->query("title");
   if (old_rank==RED+"权力帮"+NOR+rank)    {
command("say "+me->query("name")+",你这段时间武功并没多大长进啊!\n");
        return 1;        }
   command("say 依你的武功看来,可在帮中担当"+rank+"一职.\n");
   command("chat 自今日起,"+me->query("name")+"在权力帮中担任"+rank+"一职.\n");
   me->set("title",RED+"权力帮"+NOR+rank);
   tell_object(me,"你被委任为权力帮"+rank+".\n");
   return 1;
}
string check_player(object ob)
{
   int num;
   (int)num=ob->query("combat_exp");
   if (num<10000) return "帮众";
   if (num<50000) return "副香主";
   if (num<100000) return "香主";
   if (num<200000) return "副坛主";
   if (num<300000) return "坛主";
   if (num<500000) return "副堂主";
  if (num<800000) return "堂主";
  if (num<1000000) return "护法";
  if (num<1200000) return "总护法";
  if (num<1400000) return "人魔";
  if (num<1600000) return "地魔";
  if (num<1800000) return "天魔";
  else return "神魔";
 return;
}
