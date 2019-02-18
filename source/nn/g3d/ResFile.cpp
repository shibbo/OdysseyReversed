/**
 * @file ResFile.h
 * @brief Resource file for models.
 */

#include "nn/g3d/ResFile.h"

namespace nn
{
    namespace g3d
    {
        bool ResFile::IsValid(void const *src)
        {
            nn::util::BinaryFileHeader* header = (nn::util::BinaryFileHeader*)(src);
            return header->IsValid(0x2020202053455246, 8, 0, 0);
        }

        void ResFile::Relocate()
        {
            nn::util::RelocationTable* relocTable;

            if (!this->IsRelocated() & 0x1)
            {
                relocTable = this->GetRelocationTable();
                relocTable->Relocate();
            }
        }

        void ResFile::Unrelocate()
        {
            nn::util::RelocationTable* relocTable;

            if (this->IsRelocated() & 0x1)
            {
                relocTable = this->GetRelocationTable();
                relocTable->Unrelocate();
            }
        }

        ResFile* ResFile::ResCast(void *src)
        {
            nn::util::BinaryFileHeader* header = (nn::util::BinaryFileHeader*)(src);
            nn::util::RelocationTable* relocTable;

            if (src)
            {
                if (!(header->IsRelocated() & 0x1))
                {
                    relocTable = header->GetRelocationTable();
                    relocTable->Relocate();
                }

                header->IsEndianReverse();
            }   
            return (ResFile*)header;
        }

        s32 ResFile::BindTexture(nn::g3d::TextureRef (*ref)(char const *, void *), void *src)
        {
            s32 v8;

            u16 modelCount = this->mModelCount;

            if (this->mModelCount)
            {
                s32 curPos = 0;
                v8 = 0;

                do
                {
                    nn::g3d::ResModel* model = this->mModels + curPos;
                    v8 |= model->BindTexture(ref, src);
                    curPos += 0x78;
                    --modelCount;
                } 
                while (modelCount);
            }
            else
            {
                v8 = 0;
            }

            u16 matAnimCount = this->mMatAnimCount;

            if (this->mMatAnimCount)
            {
                s32 curPos = 0;

                do
                {
                    ResMaterialAnim* anim = this->mMatAnims + curPos;
                    v8 |= anim->BindTexture(ref, src);
                    curPos += 0x78;
                    --matAnimCount;
                } 
                while (matAnimCount);
            }

            return v8;
        }

        void ResFile::ReleaseTexture()
        {
            u16 modelCount = this->mModelCount;

            if (modelCount)
            {
                s32 curOffs = 0;

                do
                {
                    ResModel* curModel = this->mModels + curOffs;
                    curModel->ReleaseTexture();
                    curOffs += 0x78;
                    --modelCount;
                } 
                while (modelCount);
            }

            u16 matAnimCount = this->mMatAnimCount;

            if (matAnimCount)
            {
                s32 curOffs = 0;

                do
                {
                    ResMaterialAnim* resAnim = this->mMatAnims + curOffs;
                    resAnim->ReleaseTexture();
                    curOffs += 0x78;
                    --matAnimCount;
                } 
                while (matAnimCount);
            }
        }
    };
};