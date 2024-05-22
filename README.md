# ThumbnailToTextureTool
 Plugin that adds option to export asset thumbnail to texture on right click. 

Supports UE5.3

Default Materials available in the plugin content folder

Forked from: https://github.com/NanceDevDiaries/ThumbnailToTextureTool

# Asset Types Usability

The tool works on:
- Static Meshes
- Skeletal Meshes
- Blueprints

# Tweakable Options

There are different customizable options accessible from the Project Settings Window

- [Export path](#customize-the-export-path)
- [Export name](#customize-the-export-path)
- [Background material]()

![Image of Project Settings](/Resources/Images/project_settings.png)

## Customize the export path

If **Export Path from Asset** is **True** the path will be read from the selected asset and **Search and Replace** will be available for path modification, otherwise the path will be read from **Root Texture 2D Save Directory**.

## Customize the export name

**Thumbnail Prefix** will always append to the asset name, if **Replace Prefix** is **True** the tool will remove anything before the first underscore(included) before appending the new prefix.

## Customize the background material

**Custom Background Material** will replace the black checker in the thumbnail

**Use Transparent Background** will keep the alpha of the asset. The transparency comes from a chroma key before the export, use the material *BackgroundMaterialNoShadow* in the Plugin Content folder

*The transparency workflow is still under development for better quality*