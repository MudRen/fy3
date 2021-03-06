// lu_guanying.c
// str = 膂力, int = 悟性, cps = 定力, con = 根骨, wis = 慧根, dex = 机敏
// 97.8.18 by Aug

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int HAVE_BOOK=1;

int give_book();

void create()
{
		set_name("陆冠英", ({ "lu guanying", "lu","master" }) );
		set("title", "江南归云庄少庄主");

		set("long","陆冠英正当壮年，背厚膀宽，躯体壮健，气宇轩昂，真是位少年英雄。\n");

		set("gender", "男性");
		set("age", 24);
		set("attitude", "peaceful");
		set("class", "xiake");

		set("str", 37);
		set("int", 30);
		set("spi", 30);
		set("con", 30);
		set("cps", 30);
		set("cor", 20);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("literate", 60);


//add by musix
       set_skill("suiyu-force",60);
        set_skill("luoying-sword",60);
        set_skill("luoying-strike",60);
        set_skill("bagua-steps",60);
        set_skill("lanhua-finger",60);

                map_skill("dodge",  "bagua-steps");
                map_skill("unarmed","lanhua-finger");
                map_skill("parry",  "luoying-sword");
                map_skill("force",  "suiyu-force");
                map_skill("sword",  "luoying-sword");


        set("combat_exp", 50000);
        set("score", 5000);

		create_family("桃花岛", 3, "弟子");
	
		set("inquiry", ([
            "秘籍" : (: give_book :),
		]) );	


        setup();
        carry_object("/obj/cloth")->wear();
		add_money("silver", 56);
}

void attempt_apprentice(object ob)
 {
//        if( ((int)ob->query("cor") < 20) 
//        ||      ((int)ob->query("cps") < 20)) {
//                return;
//        }
	if(ob->query("family/generation")<=3)
	{
		command("?");
		command("say " + RANK_D->query_respect(ob) +  "这是开的什么玩笑啊？");
		return;		
	}

        command("smile");
        command("say " + RANK_D->query_respect(ob) + 
 "，本门武功博大精深，你要勤学苦练，不可有一日懈怠呀！。\n");
        command("recruit " + ob->query("id") );
 }

 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xiake");
 }
 
int accept_fight(object me)
{
	command("say 练练也好，你可小心了。\n");
	return 1;
}

int accept_kill()
{
	command("emote 叫道：小爷可不怕你！上呀！\n");
}



int give_book()
{
  object me,ob;

  me=this_player();

  if(me->query("family/family_name")!="桃花岛")
  {
	command("say 你又不是我桃花岛的弟子，怎么也来问我要东西？");
	return 1;
  }

  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");

  if(HAVE_BOOK==0)
    command("say 你来晚了，本派的轻功图解已经给别人了。");  
  else  
  {
  clone_object("/d/lu/obj/dodge_book")->move(me);

    command("say 好吧，这本轻功图解你拿去吧。");  
    message_vision("陆冠英给$n一粒轻功图解。\n",this_object(),me);   
    
    HAVE_BOOK=0;   
  }

  return 1;
}
