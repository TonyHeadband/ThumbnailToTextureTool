// Credits please, open source from NanceDevDiaries. Game on!

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ThumbnailToTextureSettings.generated.h"

/**
 * 
 */
UCLASS(config = Editor, defaultconfig)
class THUMBNAILTOTEXTURETOOL_API UThumbnailToTextureSettings : public UObject
{
	GENERATED_BODY()

	UThumbnailToTextureSettings(const FObjectInitializer& ObjectInitializer);
	
public:
	/**
	 * Export path
	 */

	/**
	 * Use the path of the selected asset
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Thumbnail To Texture Settings|Texture Export Path")
	bool bExportPathFromAsset;
	
	/**
	 * The root of the directory in which to save the exported Texture2Ds.
	*/
	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!bExportPathFromAsset"), Category = "Thumbnail To Texture Settings|Texture Export Path", meta = (ContentDir), DisplayName="Root Texture 2D Save Directory")
	FDirectoryPath RootTexture2DSaveDir;

	/**
	 * Search for string in path
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="bExportPathFromAsset"), Category = "Thumbnail To Texture Settings|Texture Export Path")
	FString PathSearchFor;

	/**
	 * Replace the string in path
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="bExportPathFromAsset"), Category = "Thumbnail To Texture Settings|Texture Export Path")
	FString PathReplaceWith;

	/**
	 * Asset name section
	 */
	
	/**
	 * The Prefix to append to the name of the exported Texture2Ds
	 */
	UPROPERTY(config, EditAnywhere, BlueprintReadWrite, Category = "Thumbnail To Texture Settings|Texture Export Name")
	FString ThumbnailPrefix;

	/**
	 * Replace prefix removing what's before the first underscore
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Thumbnail To Texture Settings|Texture Export Name")
	bool bReplacePrefix;
	
	/**
	 * If true the thumbnail texture will have a black background, if false it will use the cached thumbnail checkered texture
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!UseTransparentBackground"), Category = "Thumbnail To Texture Settings|Thumbnail Background Customization")
	bool UseCustomBackgroundMaterial;

	/**
	 * Material will be set on the background
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!UseTransparentBackground && UseCustomBackgroundMaterial", AllowedClasses="/Script/Engine.MaterialInterface"), Category = "Thumbnail To Texture Settings|Thumbnail Background Customization")
	FSoftObjectPath BackgroundMaterial;

	/**
	 * If true the thumbnail texture will have opacity and a transparent background
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="!UseCustomBackgroundMaterial"), Category = "Thumbnail To Texture Settings|Thumbnail Background Customization")
	bool UseTransparentBackground;
	
	/**
	 * Will cutoff any RGB value that is close to the transparent background color
	 */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, meta=(EditCondition="UseTransparentBackground"), Category = "Thumbnail To Texture Settings|Thumbnail Background Customization")
	float BackgroundCutoffThreshold;

	UPROPERTY(Transient)
	TObjectPtr<UMaterial> TranslucentMaterial;

	UMaterial* GetBackgroundMaterial() const;
};
