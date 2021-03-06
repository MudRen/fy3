#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("宗无畏",({"zong wuwei","zong"}));
    set("gender","男性");
    set("age",68);
    set("long","身着红袍，髭髯丛生，目中隐有青气，自然有
    一股慑人威势。\n");
    set("title",RED"幽冥山庄宗主"NOR);
    set("combat_exp",2000000);
    set("kee",2000);
    set("max_kee",2000);
    set("force",2000);
    set("max_force",2000);
    set("force_factor",50);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"我就是幽冥一派宗主，你什么事?\n",
    "道心种魔大法":"我教中无上大法，可惜早几代就失传了.\n",
    ]));
        set("shen_type",-1);
    
    set("chat_chance",3);
    set("chat_msg",({
    CYN"魔界有道，斩情灭性，人间有道，仗义行侠.\n"NOR,
    CYN"道高一尺，魔高一丈!\n"NOR,
    CYN"由魔而入道，谓之道心种魔大法。可惜久已失传。\n"NOR,
    }));
    
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("unarmed",200);
    set_skill("force",200);
    set_skill("literate",120);
    set_skill("guiyingmizong",200);
    set_skill("jiuyou-xinfa",200);
    set_skill("youming-zhang",200);
    
    map_skill("dodge","guiyingmizong");
    map_skill("unarmed","youming-zhang");
    map_skill("parry","youming-zhang");
    map_skill("force","jiuyou-xinfa");
    
create_family(RED"幽冥山庄"NOR,4,"宗主");    
    setup();
    add_money("gold",1);
 }
void attempt_apprentice(object ob)
{
  int i;
  i=ob->query("MKS")+ob->query("PKS");
  if (i<300)     {
  command("say 武学修行,便应是遇人杀人,遇佛杀佛,你杀了几个了?\n");
  return;
          }
  if (ob->query("bellicosity")>500)   {
  command("say 你杀气这样重,如何能执着修行武道,我不收你!\n");
  return;
    }
  if (ob->query("mingwang")<20000)   {
  command("say 你杀了这么多人,才这点名望,只能去做杀手,我不收.\n");
  return;
      }
  command("recruit "+ob->query("id"));
  return;
 }
  
