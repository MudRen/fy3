inherit NPC;
void create()
{
    set_name("张妈",({"zhang ma"}));
        set("shen_type",1);
    set("gender","女性");
    set("combat_exp",8000);
    set("attitude","friendly");
    set("title","女仆");
    set("age",65);
    set("long","十分拘谨，背驼身曲，年岁已十分高，显然是仆人恃候
粗手粗脚，满脸皱纹，似历尽人世间沧桑无限。.\n");
    set_skill("unarmed",30);
    setup();
add_money("silver",1);
carry_object("/obj/cloth")->wear();
}
int accept_fight(object me)
{
    command("say 在老夫面前如此猖狂,看我来教训你!\n");
    message_vision("$N身躯一挺,登是变得威猛无比!\n",this_object());
    set_name("张临意",({"zhang","zhang lingyi"}));
    set("gender","男性");
    set("combat_exp",150000);
    set("sword",120);
    set("title","阴阳剑客");
 if (!objectp(present("yinyang-sword",this_object())))
         new(__DIR__"obj/yinyang-sword")->move(this_object());
   command("wield sword");
remove_call_out("turn_off");
call_out("turn_off",300,this_object());
   return 1;
}
void turn_off()
{
    object ob;
    set_name("张妈",({"zhang ma"}));
    set("gender","女性");
    set("combat_exp",8000);
      set("title","女仆");
ob=present("yinyang-sword",this_object());
 if (ob) destruct(ob);
   return;
}   
