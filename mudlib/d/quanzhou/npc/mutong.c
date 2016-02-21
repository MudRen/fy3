inherit NPC;

void create()
{
	set_name("牧童", ({ "mutong", "kid","littleboy"}) );
	set("gender", "男性" );
	set("age", 12);
	set("long", "一个天真纯真的小牧童，坐在牛背上悠闲得吹响牧笛。\n");

	set("combat_exp",1000);
       set_skill("parry",12);
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	setup();
	carry_object("/d/quanzhou/obj/duangua")->wear();
       carry_object("/d/quanzhou/obj/mudi")->wield();
            add_money("silver",2);
}
void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("meeting");
                call_out("meeting", 1, ob);
        }
}
void meeting(object ob)
{ switch(random(3))
  {   case 1:
        command("say 天上星，亮晶晶... ...下面，下面是什么来着?\n");
        break;
      case 2:
        message_vision("$N吹起牧笛，笛声象云雀传向林外!\n",this_object());
        break;
      case 3:
       command("smile");
        break;
    }
}