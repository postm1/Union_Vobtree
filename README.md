**This plugin adds new external functions which allow you to add/remove a vobtree (a bunch of saved vobs) in Gothic 2 Night of Raven dynamically via scripts.**

**How to install:**
1. Compile it in Visual Studio (2015+)
2. Put dll file into system/autorun directory (or pack it in VDF file)
3. Add external script functions into your scripts
4. Don't add Waypoints or Freepoints into vobtree (better not)


**External script functions:** (add it in Gothic Sourcer)

func void Ext_InsertVobTree(var string path);

func void Ext_InsertVobTreeParent(var string path, var string parentName);

func void Ext_RemoveVobTree(var string vobName);




**Example of usage:**

1. Make .ZEN file with a vobtree in Spacer NET with a unique name of the parent
2. Save it in VDF file with a path _WORK/DATA/WORLD/VOBTREE (you can use any folder inside WORLD folder)
3. In scripts load vobtree when you need it.
   
   In some loop function or trigger:
   ```
   if (!CheckInsertNewVobtree_1)
   {
     CheckInsertNewVobtree_1 = TRUE;
     Ext_InsertVobTree("VOBTREE/MYVOBTREE.ZEN");
   }
   ```
5. If you need to remove a vobtree, call ```Ext_RemoveVobTree("NB_VOBTREE_ITMI_FIREBANNER");``` by vobtree's parent vob unique name (not filename)
6. If you need to insert vobtree into a specific vob with unique name use ```Ext_InsertVobTreeParent("VOBTREE/NB_VOBTREE_ORCSHIP_EFFECTS.ZEN", "EVT_NB_ORCSHIP_QUEST_FINAL");``` where VOBTREE/NB_VOBTREE_ORCSHIP_EFFECTS.ZEN is a filename, EVT_NB_ORCSHIP_QUEST_FINAL is a vobname to insert in it
   
