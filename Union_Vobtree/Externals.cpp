// Supported with union (c) 2020 Union team
// Union SOURCE file

namespace GOTHIC_ENGINE {

	
	//remove vobtree by parent name
	int RX_RemoveVobTree()
	{
		zCParser* par = parser;
		zSTRING vobName;

		par->GetParameter(vobName);

		if (!IsWorldReadyOrLoaded(false)) return 0;

		if (vobName.Length() > 0)
		{
			zCVob* pVob = ogame->GetWorld()->SearchVobByName(vobName);

			if (pVob)
			{
				zCTree<zCVob>* tree = pVob->globalVobTreeNode;
				GetChildrenPFX(tree, pVob, pVob);
				ogame->GetWorld()->RemoveVobSubtree(pVob);
			}

		}
		return 0;
	}

	//insert vobtree globally by filename
	int RX_InsertVobTree() {
		zCParser* par = parser;
		zSTRING path;

		par->GetParameter(path);

		InsertVobTree(path, "");
		return 0;
	}

	//insert vobtree by filename into a vob with name 
	int RX_InsertVobTreeParent() {
		zCParser* par = parser;

		zSTRING parentName;
		zSTRING path;


		par->GetParameter(parentName);
		par->GetParameter(path);

		InsertVobTree(path, parentName);
		return 0;
	}


	void RX_RegisterExternals()
	{
		parser->DefineExternal("Ext_InsertVobTreeParent", RX_InsertVobTreeParent, zPAR_TYPE_VOID, zPAR_TYPE_STRING, 0);
		parser->DefineExternal("Ext_InsertVobTree", RX_InsertVobTree, zPAR_TYPE_VOID, zPAR_TYPE_STRING, 0);
		parser->DefineExternal("Ext_RemoveVobTree", RX_RemoveVobTree, zPAR_TYPE_VOID, zPAR_TYPE_STRING, 0);
	}
}