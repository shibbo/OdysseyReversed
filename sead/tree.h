#pragma once

#include "types.h"

namespace sead
{
    class TreeNode
    {
        public:
        TreeNode();

        void clearLinks();
        void pushBackChild(sead::TreeNode *child);
        void detachSubTree();
        void pushBackSibling(sead::TreeNode *sibling);
        void pushFrontChild(sead::TreeNode *child);
        void insertBeforeSelf(sead::TreeNode *node);
        void insertAfterSelf(sead::TreeNode *node);
        void detachAll();
        void clearChildLinksRecursively_();
        sead::TreeNode* findRoot();
        sead::TreeNode* findRoot() const;
        u32 countChildren() const;

        sead::TreeNode* mRoot; // _0
        sead::TreeNode* mChildNode; // _8
        u64 _10;
        u64 _18;
    };
};