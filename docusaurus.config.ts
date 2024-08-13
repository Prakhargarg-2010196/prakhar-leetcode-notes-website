import {themes as prismThemes} from 'prism-react-renderer';
import type {Config} from '@docusaurus/types';
import type * as Preset from '@docusaurus/preset-classic';
import sidebars from './sidebars';

const config: Config = {
  title: 'Learnings from Leetcode Solving',
  tagline: 'This would be a repository for future reference of me and others who want to learn DSA and want to look into the thought process that goes into solving problems on leetcode',

  // Set the production url of your site here
  url: 'https://prakhar-solves-leetcode.vercel.app/',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/',
  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  // Even if you don't use internationalization, you can use this field to set
  // useful metadata like html lang. For example, if your site is Chinese, you
  // may want to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      {
        docs: {
          path:'./docs',
          sidebarPath: './sidebars.ts',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      } satisfies Preset.Options,
    ],
  ],

  themeConfig: {
     colorMode: {
      defaultMode: 'dark',
      disableSwitch: false,
      respectPrefersColorScheme: false,
    },
    navbar: {
      title: 'Prakhar Solves Leetcode',
      logo: {
        alt: 'My Site Logo',
        src: 'img/logo.png',
      },
      items: [
        {
          type: 'docSidebar',
          sidebarId: 'tutorialSidebar',
          position: 'left',
          label: 'Solved Problems',
        },
        { 
         
           position: 'left',
          label: 'Tags',
          to:'docs/tags'
        },
        
       
        
      ],
    },
    footer: {
      style: 'dark',
      links: [
            {
              label: 'Stack Overflow',
              href: 'https://stackoverflow.com/users/15645824/prakhar-garg',
            },
            {
              label: 'Discord',
              href: 'https://discordapp.com/users/838681118009196574',
            },
            {
              label: 'Twitter',
              href: 'https://x.com/praakhaaar',
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
