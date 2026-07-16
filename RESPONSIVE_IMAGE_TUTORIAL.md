# How to Create a 50% Right-Side Responsive Image Layout

## Overview
This tutorial explains how to make an image take up **50% of the right portion** of your website while keeping it **fully responsive** across all device sizes.

---

## Key Concepts

### 1. **Flexbox Layout**
We use CSS Flexbox to create a flexible container that automatically adjusts based on screen size.

### 2. **50% Width Container**
The image container takes up exactly 50% of the available width on desktop, using `flex: 0 0 50%;`

### 3. **Media Queries**
We use responsive breakpoints to change the layout on mobile devices.

---

## Implementation Breakdown

### Step 1: Set Up the Main Container

```css
#body{ 
    min-height: 500px;
    display: flex;
    gap: 10px;
}
```

**What this does:**
- `display: flex;` - Enables flexbox layout, making child elements sit side by side
- `min-height: 500px;` - Sets minimum height (changes on mobile)
- `gap: 10px;` - Adds 10px space between left and right sections

---

### Step 2: Style the Left Section (Content)

```css
#left{ 
    color: aliceblue;
    flex: 1;                    /* Takes remaining space */
    padding: 15px 12px;
    animation-name: slideUp;
    animation-duration: 4s;
    display: flex;
    flex-direction: column;     /* Stacks content vertically */
    justify-content: center;    /* Centers content vertically */
}
```

**What this does:**
- `flex: 1;` - Takes all available remaining space
- `flex-direction: column;` - Stacks heading, text, and button vertically
- `justify-content: center;` - Centers all content vertically in the container

---

### Step 3: Create the 50% Right Image Container

```css
#right{ 
    flex: 0 0 50%;              /* Exactly 50% width */
    min-width: 250px;           /* Never shrinks below 250px */
    position: relative;
    overflow: hidden;           /* Hides content outside borders */
    border-radius: 8px;
    box-shadow: 0 4px 10px rgba(0,0,0,0.15);
    display: flex;
    align-items: center;        /* Centers image vertically */
    justify-content: center;    /* Centers image horizontally */
}
```

**What this does:**
- `flex: 0 0 50%;` - **KEY RULE**: Takes exactly 50% width (doesn't shrink, doesn't grow)
  - First value (0) = no grow
  - Second value (0) = no shrink  
  - Third value (50%) = base width
- `min-width: 250px;` - On very small screens, doesn't go below 250px
- `display: flex;` inside the container - Centers the image inside

---

### Step 4: Style the Image to Be Responsive

```css
#right img {
    position: absolute;
    display: none;              /* Hidden initially */
    width: 90%;                 /* Takes 90% of container */
    max-width: 500px;           /* Never larger than 500px */
    height: auto;               /* Auto height maintains aspect ratio */
    max-height: 90%;            /* Never taller than 90% of container */
    border-radius: 25px;
    object-fit: contain;        /* Scales image to fit without cropping */
}
```

**What this does:**
- `width: 90%;` - Image takes 90% of its container width
- `height: auto;` - **IMPORTANT**: Maintains the image's original aspect ratio
- `object-fit: contain;` - Scales the image to fit entirely inside its container
- `max-width` and `max-height` - Prevents the image from getting too large

---

### Step 5: Add Responsive Media Queries

#### Tablet & Small Screen (768px and below)

```css
@media (max-width: 768px) {
    #body {
        flex-direction: column;     /* Stack vertically instead of side-by-side */
        min-height: auto;
    }
    #left {
        flex: none;                 /* Remove flex growth */
        width: 100%;                /* Take full width */
    }
    #right {
        flex: none;
        width: 100%;                /* Take full width */
        min-height: 350px;          /* Ensure visible height */
    }
    #right img {
        width: 85%;
        max-height: 400px;
    }
}
```

**What happens:**
- Layout changes from horizontal to vertical
- Image now takes full width instead of 50%
- Both sections take full width

#### Mobile Phone (480px and below)

```css
@media (max-width: 480px) {
    #left h1 {
        font-size: 24px;            /* Smaller heading on mobile */
    }
    #left p {
        font-size: 14px;            /* Smaller text on mobile */
    }
    #right {
        min-height: 300px;          /* Smaller container on mobile */
    }
}
```

**What happens:**
- Text sizes reduce for readability
- Image container becomes even smaller

---

## HTML Structure

Your HTML should look like this:

```html
<div id="body">
    <div id="left">
        <h1>Your Heading</h1>
        <p>Your text content</p>
        <button>Your Button</button>
    </div>
    <div id="right">
        <img class="myslides" src="image1.jpg" alt="">
        <img class="myslides" src="image2.jpg" alt="">
        <img class="myslides" src="image3.jpg" alt="">
    </div>
</div>
```

---

## How the Responsive Breakpoints Work

| Screen Size | Layout | Image Width |
|-------------|--------|-------------|
| **Desktop** (1200px+) | Content (50%) + Image (50%) side-by-side | 50% of page |
| **Tablet** (768px - 1199px) | Content (50%) + Image (50%) side-by-side | 50% of page |
| **Mobile** (480px - 767px) | Content full width + Image full width stacked | 100% width |
| **Small Mobile** (< 480px) | Same as mobile with smaller text | 100% width |

---

## Key Takeaways

✅ **`flex: 0 0 50%;`** - Controls the 50% width (0 = don't grow, 0 = don't shrink, 50% = base size)

✅ **`height: auto;`** - Maintains aspect ratio of images

✅ **`object-fit: contain;`** - Scales image nicely without cropping

✅ **`@media` queries** - Automatically adjust layout based on screen size

✅ **`display: flex;`** - Makes everything flexible and responsive

---

## Testing Your Responsive Layout

1. Open your website in a browser
2. Resize the browser window from wide to narrow
3. Watch the layout automatically adjust:
   - **Wide screen**: 50% left content, 50% right image
   - **Medium screen**: Same as wide
   - **Narrow screen**: Image and content stack vertically (100% width each)

You can also test on different devices:
- Desktop: 1920px, 1440px
- Tablet: 768px (iPad)
- Phone: 375px, 480px

---

## Customization Tips

Want to adjust the layout? Here are common changes:

### Change the image size percentage:
```css
#right {
    flex: 0 0 60%;  /* Now takes 60% instead of 50% */
}
```

### Adjust breakpoint:
```css
@media (max-width: 1024px) {  /* Instead of 768px */
    /* Mobile layout starts at 1024px instead */
}
```

### Change image aspect ratio:
```css
#right img {
    max-height: 500px;  /* Make it taller or shorter */
}
```

---

## Browser Support

This technique works on all modern browsers:
- ✅ Chrome 50+
- ✅ Firefox 45+
- ✅ Safari 10+
- ✅ Edge 15+
- ✅ Mobile browsers (iOS Safari, Chrome Mobile)

---

## Summary

You now have a **fully responsive image layout** that:
- Takes exactly **50% of the right side** on desktop
- **Automatically adjusts** to full width on mobile
- **Maintains aspect ratios** so images don't look distorted
- **Works on all devices** from phones to 4K monitors

Enjoy your responsive design! 🎉
