**This plugin adds new external functions which allow you to add/remove votree in game dynamically via scripts.**


**External script functions:** (add it in Gothic Sourcer)

func void RX_InsertVobTree(var string path);

func void RX_InsertVobTreeParent(var string path, var string parentName);

func void RX_RemoveVobTree(var string vobName);



**Example of usage:**

1. Make .ZEN file with a vobtree in Spacer NET with a unique name of the parent
2. Save it in VDF file with a path _WORK/DATA/WORLD/VOBTREE (you can use any folder inside WORLD folder)
3. In scripts load vobtree when u need it.
   Example:
   In some loop function or trigger:
   ```
   if (!CheckInsertNewVobtree_1)
   {
     CheckInsertNewVobtree_1 = TRUE;
     RX_InsertVobTree("VOBTREE/MYVOBTREE.ZEN");
   }
   ```
4. If you need to remove vobtree call ```RX_RemoveVobTree("NB_VOBTREE_ITMI_FIREBANNER");``` by its parent uniq name (not filename)
5. If you need to insert vobtree into a specific vob with unique name use ```RX_InsertVobTreeParent("VOBTREE/NB_VOBTREE_ORCSHIP_EFFECTS.ZEN", "EVT_NB_ORCSHIP_QUEST_FINAL");``` where VOBTREE/NB_VOBTREE_ORCSHIP_EFFECTS.ZEN is a filename, EVT_NB_ORCSHIP_QUEST_FINAL is a vobname to insert in it
   
