import { themes as prismThemes } from "prism-react-renderer";
import type { Config } from "@docusaurus/types";
import type * as Preset from "@docusaurus/preset-classic";

const config: Config = {
  title: "PG leetcode",
  tagline:
    "You would find my DSA learnings and leetcode questions solved on this website, you can refer them to learn if you want.",

  // Set the production url of your site here
  url: "https://prakhar-leetcode-notes.vercel.app/",
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: "/",
  onBrokenLinks: "ignore",
  onBrokenMarkdownLinks: "ignore",

  presets: [
    [
      "classic",
      {
        docs: {
          path: "./docs",
          sidebarPath: "./sidebars.ts",
        },
        theme: {
          customCss: "./src/css/custom.css",
        },
      } satisfies Preset.Options,
    ],
  ],

  themeConfig: {
    colorMode: {
      defaultMode: "dark",
      disableSwitch: false,
      respectPrefersColorScheme: false,
    },
    navbar: {
      title: "Prakhar Solves Leetcode",
      logo: {
        alt: "My Site Logo",
        src: "img/logo.png",
      },
      items: [
        {
          type: "docSidebar",
          sidebarId: "mainSidebar",
          position: "left",
          label: "Solved Problems",
        },
        {
          position: "left",
          label: "Tags",
          to: "docs/tags",
        },
      ],
    },
    footer: {
      style: "dark",
      links: [
        {
          label: "Stack Overflow",
          href: "https://stackoverflow.com/users/15645824/prakhar-garg",
        },
        {
          label: "Discord",
          href: "https://discordapp.com/users/838681118009196574",
        },
        {
          label: "Twitter",
          href: "https://x.com/prakhargdev",
        },
      ],
      copyright: `Copyright © ${new Date().getFullYear()} Prakhar Garg, Built with Docusaurus`,
    },
    prism: {
      theme: prismThemes.github,
      darkTheme: prismThemes.dracula,
    },
  } satisfies Preset.ThemeConfig,
};

export default config;
