# RichLinks

**RichLinks** is a lightweight Unreal Engine plugin that enables mouse-events (enter/leave) for inline links inside `URichTextBlock` widgets. It's designed for UI developers who want to trigger events or show tooltips when users hover over specific words or tags in rich text.

## Features

- Adds `<link>` tag support with real mouse-events (enter/leave)
- Clean integration with `URichTextBlock` via decorator
- Easy to use in both C++ and Blueprint widgets
- Tested with Unreal Engine 5.3

## Installation

1. Clone or copy this repository into your project’s `Plugins/` directory.
2. Regenerate project files and reopen the project.
3. Enable the **RichLinks** plugin in the editor.
4. Add the `ULinkRichTextBlockDecorator` to your `URichTextBlock`.

## Usage Example

```
This is an <link id="example">example link</>.
```

You can respond to hover events directly from Slate or use Blueprint interfaces to receive callbacks.
