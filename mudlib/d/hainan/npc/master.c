#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int HAVE_WEAPON=1;

int give_weapon();


void create()
{
        set_name(HIY"梵音神尼"NOR,({"fan yin", "shenni", "nigu","master"}));
       set("long",
"神尼名动武林,是当世两大神尼之一,据说她的武功已经到了神而名之的地步.\n");
       set("title", YEL"白云庵主持"NOR);
       set("gender", "女性");
       set("age", 96);
       set("attitude", "friendly");
       set("class","nigu");
       set("rank_info/respect", "神尼");
       set("per", 30);
        set("int", 30);
        set("inquiry", ([
                        "兵器" : (: give_weapon :),
                    "宝刃":(:give_weapon:),
                                    "宝刀":(:give_weapon:),

                ]) );   

       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 60);
       set("combat_exp", 1800000);

       set_skill("literate", 200);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("feixian-jian", 200);
        set_skill("bitao-shengong", 200);
        set_skill("baihua-zhang", 200);
        set_skill("qiongya-bufa", 200);
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "bitao-shengong");
        map_skill("sword", "feixian-jian");
        map_skill("parry", "feixian-jian");
        map_skill("dodge", "qiongya-bufa");

create_family("白云庵", 3, "传人");
setup();

        carry_object("/d/hainan/obj/bai_cloth")->wear();
        carry_object("/d/hainan/obj/yuruyi")->wield();
        add_money("gold.c",10);
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们白云庵只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
if ( (int)ob->query("spi")<20 && (int)ob->query("kar") < 20)  {
          command("shake");
        command("say 以我看这位" +
RANK_D->query_respect(ob) + "的资质不适合学我这一派武功.\n");
        return;
}

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们海南一派发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "nigu");
}
int give_weapon()
{  
  object me,ob;

  me=this_player();
if ((me->query("family/master_id")=="zhongling")&&(me->query("family/family_name")=="白云庵"))
 {
  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");

  if(HAVE_WEAPON==0)
    command("say 你来晚了，这东西已经给人取走了。");  
  else  
  {
  clone_object("/d/hainan/obj/hanyue.c")->move(me);

    command("say 钟灵这小丫头真是胡闹,这件东西你就拿去吧。");  
    message_vision("梵音神尼给$n一把寒月斩。\n",this_object(),me);   
    
    HAVE_WEAPON=0;   
  }

  return 1;
 }
else
 command("say 老尼哪来的什么神兵利刃呀,你别听那些小丫头乱说!\n");
return 1;
}

