// Room: /u/xxy/room/huayantin
inherit ROOM;

int last_time=-10000;

void create()
{
  set ("short", "华严宝塔亭");
  set ("long", @LONG
亭以塔而名,是因为亭中立一紫铜古塔(ta),此塔原置于峨眉县城南
的圣积寺内,故又名'圣积寺铜塔',亭前廊下有虎泉,泉边植有孑遗植物
'僳潞'(shu).
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ligouyuan",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "shu" : "这种树是上古之时遗留下来的,踞今有1.7亿年,其叶有药用价值
你可以摇(yao)树看看.如果运气好的话....
",
  "ta" : "此塔由紫铜制成,高5.8米,14层.塔身密密麻麻地铸满了4000多
尊佛像和'华严经'195048字,塔座刻有铭文:大明万历年万化轩施制
",
]));
set("outdoors","/d/emei");
  setup();
}
void init()
{
	add_action("do_yao", "yao");
}

int do_yao(string arg)
{
    object me,ob;
    int i;

    if(arg!="shu") return 0;
    
    me=this_player(); 
    me->set_temp("yao",me->query_temp("yao")+1);

    if(me->query_temp("yao")==4)
    {
      me->set_temp("yao",0);

      i=time();
      if((i-last_time)>900)
      {
	switch( random(2) ) 
		{
			case 0:
                            ob=new(__DIR__"obj/leaf");
                            ob->move(me);
                                 message_vision(
"$N狠命地抱着树晃动起来,不一会,树上掉下一片树叶,
$N捡起了这片树叶，小心翼翼地放入怀中。\n", me);

				break;
			case 1:
        message_vision(
"$N狠命地抱着树晃动起来,突然上面掉下来一团东西,
 正好调在$N脸上,黑呼呼的,带点臭味,哇...是鸟屎......。\n", me);
				break;
		}
        last_time=i;
      }
      else          
        message_vision("$N摇了半天树,把一只乌鸦惊上了天。\n", me); 
           
    }
    else
      message_vision("$N用力摇了一下树，僳潞晃了晃。\n", me);
   
    return 1; 
}

int valid_leave(object me, string dir)
{
  if(dir=="east") me->delete_temp("yao");

  return ::valid_leave(me, dir);  
}

