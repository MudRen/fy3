inherit ITEM;
void create()
{
  set_name("马蹄莲", ({"mati lian"}));
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一朵形状如同马蹄的白色莲花。\n");
    set("unit", "棵");
    set("value", 1000);
  }
}


